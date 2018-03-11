#ifndef _SERVER_H
#define _SERVER_H

#include <Comm.h>
#include <Message.h>
#include <Customer.h>

class Server
{
 public:
 Server(int port_num) : 
  comm(port_num) {};
  void Start();
 private:
  ServerComm comm;

  //Functions
  void ReadMessage(Message*& msg) const;
  void SendResponse(const string& response) const;

  void WaitCustomerLogin(Customer*& customer);
  void ProcessRequest(Customer* c);
};

#endif
