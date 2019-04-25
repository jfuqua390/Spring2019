#include <iostream>
#include "account.h"
#include <fstream>
using namespace std;

Account::Account() {
    balance = 0;
}

Account::Account(double balance) {
  this->balance = balance;
}

void Account::deposit(double amt) {
  balance += amt;
}

void Account::withdraw(double amt) {
  balance -= amt;
}

void Account::output() {
  cout << "Balance in Account: " << balance << endl;
}

void Account::writeToFile() {
  ofstream myfile;
  myfile.open("act.txt");
  myfile << to_string(balance);
  myfile.close();
}
