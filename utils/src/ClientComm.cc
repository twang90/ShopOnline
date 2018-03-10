#include <Comm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

ClientComm::ClientComm(int port_num, const char* host_name)
{
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) 
    error("ERROR opening socket");
  struct hostent * server = gethostbyname(host_name);
  if (server == NULL) {
    error("ERROR no such host");
  }
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, 
	(char *)&serv_addr.sin_addr.s_addr,
	server->h_length);
  serv_addr.sin_port = htons(port_num);
}

ClientComm::~ClientComm()
{
  close(sockfd);
}

void ClientComm::Connect()
{
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    error("ERROR connecting");
}

void ClientComm::Disconnect()
{}

void ClientComm::Receive(char buffer[], int len)
{
  bzero(buffer, len);
  int n = read(sockfd, buffer, len-1);
  if (n < 0) error("ERROR reading from socket");
}

void ClientComm::Send(const char buffer[], int len)
{
  int n = write(sockfd, buffer, len);
  if (n < 0) error("ERROR writing to socket");
}
