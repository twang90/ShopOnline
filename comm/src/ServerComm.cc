#include <Comm.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

ServerComm::ServerComm(int port_num)
{
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
    error("ERROR opening socket");
  struct sockaddr_in serv_addr;
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(port_num);
  if (bind(sockfd, (struct sockaddr *) &serv_addr,
           sizeof(serv_addr)) < 0)
    error("ERROR on binding");
  // Prepare to connect to client
  newsockfd = -1;
}

ServerComm::~ServerComm()
{
  close(sockfd);
}

void ServerComm::Connect()
{
  listen(sockfd,5);
  struct sockaddr_in cli_addr;
  socklen_t clilen = sizeof(cli_addr);
  newsockfd = accept(sockfd, 
		     (struct sockaddr *) &cli_addr, 
		     &clilen);
  if (newsockfd < 0)
    error("ERROR on accept");
}

void ServerComm::Disconnect()
{
  if (newsockfd < 0)
    error("ERROR on disconnect");
  close(newsockfd);
}

void ServerComm::Receive(char buffer[], int len)
{
  bzero(buffer, len);
  int n = read(newsockfd, buffer, len-1);
  if (n < 0) error("ERROR reading from socket");
}

void ServerComm::Send(const char buffer[], int len)
{
  int n = write(newsockfd, buffer, len);
  if (n < 0) error("ERROR writing to socket");
}
