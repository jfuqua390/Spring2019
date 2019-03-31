#include <iostream>
#include <string>
using namespace std;

//Write a program that reads an integer between 0 and 1000 and adds all the digits in the integer. For example, if an integer is 932, the sum of all its digits is 14.
//Hint: Use the % operator to extract digits, and use the / operator to remove the extracted digit. For instance, 932 % 10 = 2 and 932 / 10 = 93.

int main() {
  cout << "Enter an integer between 0 and 1000: ";
  int number;
  cin >> number;
  int sum;

  //If we want to include the number 1000, we would need one more if statement, but the question states between 0 and 1000 so I don't think we include those two numbers
  if(number >= 100) {
    sum = (number % 10) + (number / 10) % 10 + (number / 100) % 10;
  } else if(number >= 10) {
    sum = (number % 10) + (number / 10) % 10;
  } else {
    sum = number;
  }

  cout << "Sum of digits: " << sum << endl;
}
