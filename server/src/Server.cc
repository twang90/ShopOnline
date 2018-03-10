#include <Server.h>
#include <stdio.h>

#define PORT_NUM 1234

void Server::Start()
{
  comm.Prepare(PORT_NUM);
  while (1){
    int newsockfd = comm.Connect();
    char buffer[256];
    comm.Receive(newsockfd, buffer, 256);
    printf("Here is the message: %s",buffer);
    comm.Send(newsockfd, "I got your message", 18);
    comm.Disconnect(newsockfd);
  }
}
