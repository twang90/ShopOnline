#include <string>
#include <Message.h>

void error(const char* msg)
{
  perror(msg);
  exit(1);
}

static Message::Action MatchAction(const string& msg, size_t pos)
{
  if (msg.compare(1, pos-1, "NAME") == 0){
    return Message::NAME;
  }
  else{
    error("Other actions are not supported yet!");
  }
}

static string TranslateAction(Message::Action act)
{
  if (act == Message::NAME)
    return "NAME";
  else{
    error("Other actions are not supported yet!");
  }
}

Message::Message(const char msg[])
{
  if (msg[0] != '['){
    printf("%s\n", msg);
    error("Message Wrong: First char is not [");
    exit(1);
  }
  string message(msg);
  size_t act_end = message.find(']');
  if (act_end == string::npos){
    error("Message Wrong: no ] is found");
  }
  act = MatchAction(message, act_end);
  size_t aster = message.find('*');
  if (aster == string::npos){
    name = message.substr(act_end+1);
    count = 1;
  }
  else{
    name = message.substr(act_end+1, aster-act_end-1);
    count = message.substr(aster+1);
  }
}

#include <string.h>
char* Message::GetMessage() const
{
  string message = '[' + 
    TranslateAction(act) + ']' +
    name;
  if (GetCount() > 1)
    message += '*' + count;
  char* msg = strdup(message.c_str());
  printf("%s\n", msg);
  return msg;
}
