#ifndef _CLIENT_H
#define _CLIENT_H

#include <Comm.h>
#include <Message.h>

class Client
{
 public:
 Client(int port_num, const char* host_name) : 
  comm(port_num, host_name) {};
  void Start();
 private:
  ClientComm comm;
  void PrintNamePrompt() const;
  string ReadString() const;
  void SendMessage(const Message& msg) const;
  void PrintResponse() const;
  void PrintActionPrompt() const;
  bool ReadRequest(Message* msg) const;
  void SendCustomerInfo();
  void SendRequests();
};

#endif
