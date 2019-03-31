#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Twin primes are a pair of prime numbers that differ by 2.
For example, 3 and 5 are twin primes, 5 and 7 are twin primes, and 11 and 13 are twin primes.
Write a program to find all twin primes less than 1,000. Display the output as follows:

             (3, 5)
             (5, 7)
             ...
*/

bool is_prime(int n) {
  if(n < 2) {
    return false;
  }
  for (int i = 2; i <= n / 2; i++) {
    if(n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  for (int i = 2; i < 1000; i++) {
    if(is_prime(i) && is_prime(i+2)) {
      cout << "(" << i << ", " << i+2 << ")" << endl;
    }
  }
}
