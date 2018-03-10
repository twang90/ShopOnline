#include <Client.h>

int main(int argc, char *argv[])
{
  Client client(1234, "localhost");
  client.Start();
  return 0;
}
