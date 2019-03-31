#include <iostream>
#include <string>
using namespace std;

int main() {
  //Declare Variables
  int n;
  int result = 1;
  cout << "Enter an integer: ";
  cin >> n;

  //n = 0
  if(n <= 0) {
    result = 0;
  } else if(n % 2 == 0) { // n is even
    result = 1;
    for(int i = 2; i <= n; i+=2) { //skip every other
      result *= i;
    }
  } else { // n is odd
    result = 1;
    for(int i = 1; i <= n; i+=2) { //skip every other
      result *= i;
    }
  }
  cout << result <<" is result" << endl;
  return result;
}
