#ifndef _SERVER_H
#define _SERVER_H

#include <Comm.h>

class Server
{
 public:
  Server() {};
  void Start();
 private:
  Comm comm;
};

#endif
