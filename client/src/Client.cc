#include <Client.h>
#include <string.h>
#include <stdio.h>

void Client::Start()
{
  comm.Connect();
  printf("Please enter the message: ");
  char buffer[256];
  bzero(buffer,256);
  fgets(buffer,255,stdin);
  comm.Send(buffer, strlen(buffer));
  comm.Receive(buffer, 256);
  printf("%s\n",buffer);
}
