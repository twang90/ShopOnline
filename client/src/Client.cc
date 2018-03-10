#include <Client.h>
#include <string.h>
#include <stdio.h>
#include <Message.h>

static void TrimEndline(char buffer[])
{
  size_t len = strlen(buffer);
  if (len > 0 && buffer[len-1] == '\n') {
    buffer[--len] = '\0';
  }
}

void Client::Start()
{
  // Step 1: Send user info to the server
  SendCustomerInfo();

  while (1) {}
}

void Client::SendCustomerInfo()
{
  printf("Please enter Your Name:");
  // Take input from programmer
  char buffer[256];
  bzero(buffer,256);
  fgets(buffer,255,stdin);
  TrimEndline(buffer);
  // Format a message to send to server
  Message msg(Message::NAME, buffer);
  comm.Connect();
  char* message = NULL;
  message = msg.GetMessage();
  comm.Send(message, strlen(message));
  free(message);
  // Wait for response from server
  comm.Receive(buffer, 256);
  printf("%s\n", buffer);
}
