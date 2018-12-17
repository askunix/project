#include"protocol.h"

//创建节点
SLN *BuyNode(int sockfd)
{
  SLN *node = (SLN*)malloc(sizeof(SLN));
  if(node == NULL)
  {
    perror("malloc");
    exit(1);
  }
  node->_sockfd = sockfd;
  node->_prev = NULL;
  node->_next = NULL;
  return node;
}


SLN *phead = NULL;

int Serverdo()
{
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  if(fd < 0)
  {
    perror("socket");
    exit(2);
  }
  //填充自己的套接字信息
  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr = inet_addr(IP);

  if(bind(fd, (struct sockaddr *)&server, sizeof(server)) < 0)
  {
    perror("bind");
    exit(3);
  }

  if(listen(fd, 5) < 0)
  {
    perror("listen");
    exit(4);
  }

  return fd;
}



void func(void *arg)
{
  SLN *node = (SLN*)arg;
  SLN *cur = NULL;
  char buf[NAME + MSG] = {0};
  while(1)
  {
    while(1)
    {
      ssize_t rec = recv(node->_sockfd, buf, NAME + MSG, 0);
      if(rec <= 0)
      {
        printf("recv failed\n");
        break;
      }

      cur = phead->_next;

      while(cur != NULL)
      {
        send(cur->_sockfd, buf, NAME + MSG, MSG_DONTWAIT);
        cur = cur->_next;
      }
    }

    //删除节点
    node->_prev->_next = node->_next;
    if(node ->_next != NULL)
    {
      node->_next->_prev = node->_prev;
    }

    node->_prev = NULL;
    node->_next = NULL;
    free(node);
    close(node->_sockfd);

  }
}



void working(int sockfd)
{
  int new_sockfd = 0;
  while(1)
  {
    new_sockfd = accept(sockfd, NULL, NULL);
    if(new_sockfd < 0)
    {
      perror("accept");
      continue;
    }

    //头插节点，保存客户端套接字
    SLN *node = BuyNode(new_sockfd);
    node->_next = phead->_next;
    node->_prev = phead;
    if(phead->_next != NULL)
    {
      phead->_next->_prev = node;
    }
    phead->_next = node;

    pthread_t thread = 0;
    pthread_create(&thread, NULL, (void *)func, (void *)node);
    pthread_detach(thread);
  }
  close(sockfd);
}



int main()
{
  phead = BuyNode(0);
  int sockfd = Serverdo();
  working(sockfd);
  printf("Init OK\n");
  return 0;
}




