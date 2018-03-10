#ifndef _COMM_H
#define _COMM_H

class Comm
{
 public:
  Comm() {}
  void Prepare(int port_num);
  void Receive(int newsockfd, char buffer[], int len);
  void Send(int newsockfd, const char buffer[],int len);
  int Connect();
  void Disconnect(int);
 private:
  int sockfd;
};

#endif
