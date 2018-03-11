#include <string>
#include <Message.h>
#include <assert.h>

void error(const char* msg)
{
  perror(msg);
  exit(1);
}

static Message::Action MatchAction(const string& msg, size_t pos)
{
  if (msg.compare(1, pos-1, "LOGIN") == 0){
    return Message::LOGIN;
  }
  else if (msg.compare(1, pos-1, "BUY") == 0){
    return Message::BUY;
  }
  else if (msg.compare(1, pos-1, "INQUIRY") == 0){
    return Message::INQUIRY;
  }
  else if (msg.compare(1, pos-1, "RETURN") == 0){
    return Message::RETURN;
  }
  else if (msg.compare(1, pos-1, "LOGOUT") == 0){
    return Message::LOGOUT;
  }
  printf("[DEBUG]%s\n", msg.c_str());
  error("Other actions are not supported yet!");
  return Message::NOP;
}

static string TranslateAction(Message::Action act)
{
  if (act == Message::LOGIN)
    return "LOGIN";
  else if (act == Message::BUY)
    return "BUY";
  else if (act == Message::INQUIRY)
    return "INQUIRY";
  else if (act == Message::RETURN)
    return "RETURN";
  else if (act == Message::LOGOUT)
    return "LOGOUT";
  printf("[DEBUG]Action: %d\n", act);
  error("Other actions are not supported yet!");
  return "";
}

Message::Message(const char msg[])
{
  if (strlen(msg) == 0){
    valid = false;
    return;
  }
  valid = true;
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
    count = "1";
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
  return msg;
}
