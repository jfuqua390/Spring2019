#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Write a method with the following header to display an integer in reverse order:

void reverse(int number)

For example, reverse(3456) displays 6543.
Write a test program that prompts the user to enter an integer and displays its reversal.
*/

void reverse(int number) {
  while(number > 0) {
    cout << number % 10;
    number /= 10;
  }
  cout << endl;
}

int main() {
  int x;
  cout << "Enter a number: ";
  cin >> x;
  reverse(x);
}
