#include <Server.h>
#include <stdio.h>

void Server::Start()
{
  while (1){
    comm.Connect();
    char buffer[256];
    comm.Receive(buffer, 256);
    printf("Here is the message: %s",buffer);
    comm.Send("I got your message", 18);
    comm.Disconnect();
  }
}
