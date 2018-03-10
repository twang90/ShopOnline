#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer
{
 public:
 Customer(const string& n) : name (n) {};
  string GetName() const { return name; };
 private:
  string name;
};

#endif
