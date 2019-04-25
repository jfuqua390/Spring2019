// #include "transaction.h"

class Account {
private:
  double balance;
public:
  Account();
  Account(double balance);
  void deposit(double amt);
  void withdraw(double amt);
  void output();
  void writeToFile();
};
