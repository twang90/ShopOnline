#ifndef _CLIENT_H
#define _CLIENT_H

#include <Comm.h>

class Client
{
 public:
 Client(int port_num, const char* host_name) : 
  comm(port_num, host_name) {};
  void Start();
 private:
  ClientComm comm;
};

#endif
