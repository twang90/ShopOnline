#include <Server.h>
#include <stdio.h>
#include <assert.h>

void Server::Start()
{
  while (1){
    comm.Connect();
    // Step 1: Wait for a customer to log in
    Customer* customer = NULL;
    WaitCustomerLogin(customer);

    // Step 2: Process the customer's requests
    ProcessRequest(customer);
    free(customer);
    comm.Disconnect();
  }
}

void Server::WaitCustomerLogin(Customer*& customer)
{
  // TODO: Need to figure out the client info
  Message* msg = NULL;
  ReadMessage(msg);
  assert(msg);
  assert(msg->GetAction() == Message::LOGIN);
  customer = new Customer(msg->GetName());
  SendResponse("Welcome New Client: " + customer->GetName());
  printf("[LOG]New Customer <%s> is online\n", customer->GetName().c_str());
  free(msg);
}

void Server::ReadMessage(Message*& msg) const
{
  char buffer[256];
  comm.Receive(buffer, 256);
  msg = new Message(buffer);
  assert(msg);
  printf("[LOG]Message received: %s\n", msg->GetMessage());
}

void Server::ProcessRequest(Customer* c)
{
  Message* msg = NULL;
  while (1) {
    msg = NULL;
    ReadMessage(msg);
    if (msg->GetAction() == Message::BUY){
      c->BuyItems(msg->GetName(), msg->GetCount());
      SendResponse("Request to buy " + msg->GetName() + " * " + to_string(msg->GetCount()) + " is received");
    }
    else if (msg->GetAction() == Message::INQUIRY){
      c->Inquiry(msg->GetName());
      SendResponse("Request to inquire " + msg->GetName() + " is received");
    }
    else if (msg->GetAction() == Message::RETURN){
      c->ReturnItems(msg->GetName(), msg->GetCount());
      SendResponse("Request to return " + msg->GetName() + " * " + to_string(msg->GetCount()) + " is received");
    }
    else if (msg->GetAction() == Message::LOGOUT){
      printf("[LOG]Customer<%s> logs out\n", c->GetName().c_str());
      break;
    }
  }
}

void Server::SendResponse(const string& response) const
{
  comm.Send(response.c_str(), response.length());
}
