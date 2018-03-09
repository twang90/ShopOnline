#include <Comm.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
void Comm::Prepare(int port_num)
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
}

int Comm::Connect()
{
  listen(sockfd,5);
  struct sockaddr_in cli_addr;
  socklen_t clilen = sizeof(cli_addr);
  int newsockfd = accept(sockfd, 
		     (struct sockaddr *) &cli_addr, 
		     &clilen);
  if (newsockfd < 0) 
    error("ERROR on accept");
  return newsockfd;
}

void Comm::Disconnect(int newsockfd)
{
  close(newsockfd);
}

void Comm::Receive(char& buffer[], int len)
{
  int newsockfd = Connect();
  bzero(buffer, len);
  n = read(newsockfd, buffer, len-1);
  Disconnect(newsockfd);
}

void Comm::Send(const char& buffer[], int len)
{
  int newsockfd = Connect();
  n = write(newsockfd,"I got your message",18);
  if (n < 0) error("ERROR writing to socket");
  Disconnect(newsockfd);
}

