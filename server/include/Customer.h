#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer
{
 public:
 Customer(const string& n) : name (n) {};
  string GetName() const { return name; };
  void BuyItems(string Item, int count){}
  void Inquiry(string Item) const {}
  void ReturnItems(string Item, int count) {}
 private:
  string name;
};

#endif
