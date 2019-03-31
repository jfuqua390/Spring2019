#include <iostream>
#include <string>
using namespace std;

//Write a program that reads the subtotal and the gratuity rate, then computes the gratuity and total.
//For example, if the user enters 10 for subtotal and 15% for gratuity rate, the program displays $1.5 as gratuity and $11.5 as total.

int main() {
  //prompt user for subtotal
  cout << "Enter subtotal: ";
  double subtotal;
  cin >> subtotal;

  cout << "Enter gratuity rate (Ex. 15%): ";
  double gratuity_rate;
  cin >> gratuity_rate;

  double gratuity;
  gratuity = (gratuity_rate / 100) * subtotal;

  double total;
  total = subtotal + gratuity;

  cout << "Total: $" << total << " Gratuity: $" << gratuity << endl;
  return 0;
}
