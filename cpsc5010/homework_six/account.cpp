#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Account {
  private:
    int id;
    double balance;
    double annualInterestRate;
    string dateCreated;

  public:
    //Default Constructor
    Account() {
      id = 0;
      balance = 0;
      annualInterestRate = 0;
      //using a string because C++ has no date class so not sure what you want here as ctime may be beyond this class
      dateCreated = "3/10/2019";
    }

    //Parameratized Constructor
    Account(int _id, double _balance) {
      id = _id;
      balance = _balance;
      annualInterestRate = 0;
      dateCreated = "3/10/2019";
    }

    //accessor and mutator for ID
    int getID() {
      return id;
    }
    void setID(int _id) {
      id = _id;
    }

    //accessor and mutator for balance
    double getBalance() {
      return balance;
    }
    void setBalance(double _balance) {
      balance = _balance;
    }

    //accessor and mutator for interest
    double getAnnualInterestRate() {
      return annualInterestRate;
    }
    void setAnnualInterestRate(double _rate) {
      annualInterestRate = _rate;
    }

    //accessor for dateCreated
    string getDateCreated() {
      return dateCreated;
    }

    //method to get monthly interest rate
    double getMonthlyInterestRate() {
      return annualInterestRate / 100 / 12;
    }

    //method to get monthly interest
    double getMonthlyInterest() {
      return getMonthlyInterestRate() * balance;
    }

    //method to withdraw from account
    void withdraw(double amount) {
      balance -= amount;
    }

    //method to deposit into Account
    void deposit(double amount) {
      balance += amount;
    }
};

int main() {
  Account testAccount(1122, 20000);
  testAccount.setAnnualInterestRate(4.5);
  testAccount.withdraw(2500);
  testAccount.deposit(3000);
  cout << "Balance: " << testAccount.getBalance() << endl;
  cout << "Monthly Interest: " << testAccount.getMonthlyInterest() << endl;
  cout << "Date Created: " << testAccount.getDateCreated() << endl;
  return 0;
}
