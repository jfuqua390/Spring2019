#include <iostream>
#include <string>
using namespace std;

/*
Suppose you save $100 each month into a savings account with the annual interest rate 5%. Thus, the monthly interest rate is 0.05/12 = 0.00417.

After the first month, the value in the account becomes
         100 * (1 + 0.00417) = 100.417
After the second month, the value in the account becomes
         (100 + 100.417) * (1 + 0.00417) = 201.252
After the third month, the value in the account becomes
         (100 + 201.252) * (1 + 0.00417) = 302.507

Write a program that prompts the user to enter a monthly saving amount and displays the account value after the sixth month.
*/

int main() {
  cout << "Enter the amount to save each month: ";
  double amount_to_save;
  cin >> amount_to_save;

  cout << "Enter the annual interest rate (Ex: 5%): ";
  double interest;
  cin >> interest;

  double monthly_interest;
  monthly_interest = interest / 100 / 12;

  int i;
  double account_value;
  for(i = 1; i < 7; i++) {
    if(i == 0) {
      account_value = amount_to_save * (1 + monthly_interest);
    } else {
      account_value = (account_value + amount_to_save) * (1 + monthly_interest);
    }
  }

  cout << "Account value after the sixth month: " << account_value << endl;
}
