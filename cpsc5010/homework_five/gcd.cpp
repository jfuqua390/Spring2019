#include <iostream>
using namespace std;

/*
The gcd(m, n) can also be defined recursively as follows:

if  m% n is 0,   gcd(m, n) is n;   Otherwise, gcd(m, n) is gcd(n, m % n).

Write a recursive method to find the GCD.
Write a test program that prompts the user to enter two integers and displays their GCD.
*/

int gcd(int m, int n) {
  if(n != 0) {
    return gcd(n, m % n);
  } else {
    return m;
  }
}

int main() {
  int m, n;
  cout << "Enter two positive integers: ";
  cin >> m >> n;

  cout << "GCD of " << m << " and " << n << " is " << gcd(m, n) << endl;
  return 0;
}
