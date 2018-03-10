#include <Comm.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void Comm::error(const char *msg) const
{
  perror(msg);
  exit(1);
}


