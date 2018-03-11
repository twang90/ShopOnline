#include <Server.h>

int main(int argc, char *argv[])
{
  int port_num = 1234;
  if (argc > 1){
    port_num = stoi(argv[1]);
  }
  Server server(port_num);
  server.Start();
  return 0;
}
