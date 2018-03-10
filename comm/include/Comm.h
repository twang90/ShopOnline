#ifndef _COMM_H
#define _COMM_H

#include <netinet/in.h>

class Comm
{
 public:
  Comm() {}
  virtual void Receive(char buffer[], int len) = 0;
  virtual void Send(const char buffer[],int len) = 0;
  virtual void Connect() = 0;
  virtual void Disconnect() = 0;
 protected:
  void error(const char *msg);
};

class ClientComm : public Comm
{
 public:
  ClientComm(int port_num, const char* host_name);
  ~ClientComm();
  virtual void Receive(char buffer[], int len);
  virtual void Send(const char buffer[],int len);
  virtual void Connect();
  virtual void Disconnect();
 private:
  int sockfd;
  struct sockaddr_in serv_addr;
};

class ServerComm : public Comm
{
 public:
  ServerComm(int port_num);
  ~ServerComm();
  virtual void Receive(char buffer[], int len);
  virtual void Send(const char buffer[],int len);
  virtual void Connect();
  virtual void Disconnect();
 private:
  int sockfd;
  int newsockfd;
};
#endif
