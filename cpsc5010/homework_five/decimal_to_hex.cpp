#include <iostream>
#include <string>
using namespace std;

/*
Write a recursive method that converts a decimal number into a hex number as a string. The method header is:

string decimalToHex(int value)
Write a test program that prompts the user to enter a decimal number and displays its hex equivalent.
*/

string decimalToHex(int value, string result) {
  if(value == 0) {
    return result;
  }
  int remainder = value % 16;
  char x = remainder + '0';

  switch(remainder) {
    case 10: result = "A" + result; break;
    case 11: result = "B" + result; break;
    case 12: result = "C" + result; break;
    case 13: result = "D" + result; break;
    case 14: result = "E" + result; break;
    case 15: result = "F" + result; break;
    default: result = x + result; break;
  }

  return decimalToHex(value / 16, result);
}

int main() {
  int x;
  cout << "Enter an integer: ";
  cin >> x;

  cout << "Hexadecimal of " << x << " is " << decimalToHex(x, "") << endl;
}
