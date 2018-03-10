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
  void FindClientInfo();
};

#endif
