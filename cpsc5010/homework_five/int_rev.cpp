#include <iostream>
using namespace std;

/*
Write a recursive function that displays an int value reversely on the console using the following header:

void reverseDisplay(int value)
For example, reverseDisplay(12345) displays 54321.
Write a test program that prompts the user to enter an integer and displays its reversal.
*/

void reverseDisplay(int value) {
  if(value == 0) {
    return;
  } else {
    cout << value % 10;
    reverseDisplay(value / 10);
  }
}

int main() {
  int x;
  cout << "Enter a number: ";
  cin >> x;
  reverseDisplay(x);
  cout << endl;
}
