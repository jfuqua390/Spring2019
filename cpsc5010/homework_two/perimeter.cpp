#include <iostream>
#include <string>
using namespace std;

//Write a program that reads three edges for a triangle and computes the perimeter if the input is valid.
//Otherwise, display that the input is invalid. The input is valid if the sum of every pair of two edges is greater than the remaining edge.

int main() {
  float a,b,c;
  cout << "Enter values for sides a, b, and c: " << endl;
  cin >> a >> b >> c;
  float perimeter = 0;

  if(a+b > c && a+c > b && b+c > a) {
    perimeter = a + b + c;
    cout << "Perimeter: " << perimeter << endl;
  } else {
    cout << "Invalid input" << endl;
  }
}
