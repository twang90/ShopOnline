#ifndef _COMM_H
#define _COMM_H

class Comm
{
 public:
  Comm(int port_num) {}
  void Prepare(int port_num);
  void Receive(char& buffer[], int len);
  void Send(const char& buffer[],int len);
 private:
  int sockfd;
  int Connect();
  void Disconnect(int);
};

#endif
