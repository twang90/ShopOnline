#include <Server.h>
#include <stdio.h>
#include <assert.h>

void Server::Start()
{
  while (1){
    comm.Connect();
    // Step 1: Talk to client to find out its info
    FindClientInfo();
    //ProcessRequest();
    comm.Disconnect();
  }
}

void Server::FindClientInfo()
{
  // TODO: Need to figure out the client info
  char buffer[256];
  comm.Receive(buffer, 256);
  Message msg(buffer);
  assert(msg.GetAction() == Message::NAME);
  Customer customer(msg.GetName());
  string response = "Welcome New Client: " + customer.GetName();
  comm.Send(response.c_str(), response.length());
  printf("[LOG]New Customer <%s> is online\n", customer.GetName().c_str());
}

/*
void Server::ProcessRequest()
{
  Request req = ParseRequest(input);
  
}
*/
