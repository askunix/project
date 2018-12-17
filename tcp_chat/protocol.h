#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<pthread.h>


#define NAME 10
#define MSG 1024
#define IP "172.27.0.3"
#define PIP "118.24.76.81"
#define PORT 1025


typedef struct SocketListNode
{
  int _sockfd;
  struct SocketListNode *_prev;
  struct SocketListNode *_next;
}SLN;


typedef struct User
{
  char _name[NAME];
  char _msg[MSG];
}user;

#endif













