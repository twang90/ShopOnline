#include <Client.h>

int main(int argc, char *argv[])
{
  int port_num = 1234;
  string host_name("localhost");
  if (argc == 2){
    port_num = stoi(argv[1]);
  }
  if (argc == 3){
    host_name = argv[2];
  }
  Client client(port_num, host_name.c_str());
  client.Start();
  return 0;
}
