#include"protocol.h"
int ClientDo(char **argv)
{
  int fd = socket(AF_INET,
      SOCK_STREAM, 0);
  if(fd < 0)
  {
    perror("sock");
    exit(2);
  }

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr = inet_addr(PIP);

  if(connect(fd, (struct sockaddr *)&server, sizeof(server)) < 0)
  {
    perror("connect");
    exit(3);
  }
  return fd;
}


void working(int sockfd, char *name)
{
  if(fcntl(0, F_SETFL, FNDELAY) < 0)
  {
    perror("fcntl");
    exit(4);
  }

  user u;
  char buf[NAME + MSG] = {0};

  while(1)
  {
    strncpy(buf, name, NAME);

    ssize_t r = read(0, u._msg, MSG);
    if(r > 0)
    {
      u._msg[r] = 0;
      fflush(stdout);
      strcpy(buf + NAME, u._msg);
      send(sockfd, buf, NAME + MSG, MSG_DONTWAIT);
    }

    ssize_t rec = recv(sockfd, buf, NAME + MSG, MSG_DONTWAIT);
    if(rec > 0)
    {
      strncpy(u._name, buf, NAME);
      strncpy(u._msg, buf + NAME, MSG);
      printf("[%s] %s ", u._name, u._msg);
    }
  }
  close(sockfd);
}



int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    printf("less ^^^ \n");
    return 1;
  }

  int sockfd = ClientDo(argv);
  working(sockfd, argv[1]);
  return 0;
}


