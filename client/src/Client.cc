#include <Client.h>
#include <string.h>
#include <stdio.h>
#include <Message.h>
#include <assert.h>

static void TrimEndline(char buffer[])
{
  size_t len = strlen(buffer);
  if (len > 0 && buffer[len-1] == '\n') {
    buffer[--len] = '\0';
  }
}

void Client::Start()
{
  comm.Connect();
  // Step 1: Send user info to the server
  SendCustomerInfo();
  // Step 2: Wait user to send requests
  SendRequests();
  comm.Disconnect();
}

void Client::SendCustomerInfo()
{
  PrintNamePrompt();
  string name = ReadString();
  Message msg(Message::LOGIN, name);
  SendMessage(&msg);
  PrintResponse();
}

void Client::SendRequests()
{
  while (1){
    PrintActionPrompt();
    Message* msg = NULL;
    bool quit = ReadRequest(msg);
    if (quit){
      SendMessage(msg);
      free(msg);
      break;
    }
    SendMessage(msg);
    free(msg);
    PrintResponse();
  }
}

void Client::PrintNamePrompt() const
{
  printf("Please enter Your Name: ");
}


string Client::ReadString() const
{
  char buffer[256];
  bzero(buffer, 256);
  fgets(buffer, 255, stdin);
  TrimEndline(buffer);
  return string(buffer);
}

void Client::PrintResponse() const
{
  char buffer[256];
  bzero(buffer, 256);
  comm.Receive(buffer, 256);
  printf("%s\n", buffer);
}

void Client::PrintActionPrompt() const
{
  printf("========================\n");
  printf("How can I help you?\n");
  printf("[b] Buy New Items\n");
  printf("[i] Inquiry\n");
  printf("[r] Return Items\n");
  printf("[q] Quit Program\n");
}

bool Client::ReadRequest(Message*& msg) const
{
  string str = ReadString();
  Message::Action act;
  string name, count;
  switch (str[0]){
  case 'b':
    act = Message::BUY;
    printf("So you want to buy what?\n");
    name = ReadString();
    printf("And how many?\n");
    count = ReadString();
    msg = new Message(act, name, count);
    return false;
  case 'i':
    act = Message::INQUIRY;
    printf("So you want to check what?\n");
    name = ReadString();
    msg = new Message(act, name);
    return false;
  case 'r':
    act = Message::RETURN;
    printf("So you want to return what?\n");
    name = ReadString();
    printf("And how many?\n");
    count = ReadString();
    msg = new Message(act, name, count);
    return false;
  case 'q':
    act = Message::LOGOUT;
    msg = new Message(act);
    return true;
  default:
    assert(0);
  }
}

void Client::SendMessage(const Message* msg) const
{
  char* message = NULL;
  message = msg->GetMessage();
  printf("[DEBUG]Prepare to send message: %s\n", message);
  comm.Send(message, strlen(message));
  free(message);
}
