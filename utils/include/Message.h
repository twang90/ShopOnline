#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
using namespace std;

class Message
{
 public:
  enum Action{
    NAME = 0,
    BUY,
    INQUIRY,
    RETURN
  };
 Message(Action a, const char n[]):
  act(a), name(n), count("1") {};
 Message(Action a, const char n[], string c):
  act(a), name(n), count(c) {};
 Message(Action a, string n):
  act(a), name(n), count("1") {};
 Message(Action a, string n, string c):
  act(a), name(n), count(c) {};
  Message(const char[]);

  char* GetMessage() const;
  Action GetAction() const {return act;}
  string GetName() const {return name;}
  int GetCount() const {return stoi(count);}
 private:
  Action act;
  string name;
  string count;
};

#endif
