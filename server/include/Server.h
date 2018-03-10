#ifndef _SERVER_H
#define _SERVER_H

#include <Comm.h>

class Server
{
 public:
 Server(int port_num) : 
  comm(port_num) {};
  void Start();
 private:
  ServerComm comm;
};

#endif
