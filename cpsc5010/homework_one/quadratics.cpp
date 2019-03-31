#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
Compute the two roots of a quadratic equation ax2 + bx + c = 0.

b2 - 4ac is called the discriminant of the quadratic equation.
If it is positive, the equation has two real roots. If it is zero, the equation has one root. If it is negative, the equation has no real roots.

Write a program that prompts the user to enter values for a, b, and c and displays the result based on the discriminant.
If the discriminant is positive, display two roots. If the discriminant is 0, display one root. Otherwise, display “The equation has no real roots”.

x2+5x+6
9x2+6x+1
10x2+3x+15
*/

int main() {
  float a,b,c;
  cout << "Enter values for a, b, and c: " << endl;
  cin >> a >> b >> c;

  if(a == 0 || b == 0) {
    cout << "Not a valid equation." << endl;
    return 0;
  }

  double discriminant;
  discriminant = b*b - 4*a*c;
  cout << "Discriminant: " << discriminant << endl;

  float root_1;
  float root_2;
  if(discriminant > 0) {
    root_1 = (-b + sqrt(discriminant)) / (2*a);
    root_2 = (-b - sqrt(discriminant)) / (2*a);
    cout << "Root 1: " << root_1 << " and Root 2: " << root_2 << endl;
  } else if(discriminant == 0) {
    root_1 = -b / (2*a);
    cout << "This equation only has one root: " << root_1 << endl;
  } else {
    cout << "The equation has no real roots" << endl;
  }
}
