#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

/*
x2+5x+6
9x2+6x+1
10x2+3x+15
*/
class QuadraticEquation {
  private:
    float a,b,c;

  public:
    //constructor for arguments a,b,c
    QuadraticEquation(float _a, float _b, float _c) {
      a = _a;
      b = _b;
      c = _c;
    }

    //get methods for a,b,c
    float getA() {
      return a;
    }
    float getB() {
      return b;
    }
    float getC() {
      return c;
    }

    //method to get discriminant
    float getDiscriminant() {
      return (b*b) - (4*a*c);
    }

    //methods to get root1 and root2
    float getRoot1() {
      if(getDiscriminant() > 0) {
        return (-b + sqrt(getDiscriminant()) / (2*a));
      } else if(getDiscriminant() == 0) {
        return -b / (2*a);
      }
    }
    float getRoot2() {
      if(getDiscriminant() > 0) {
        return (-b - sqrt(getDiscriminant()) / (2*a));
      } else if(getDiscriminant() == 0) {
        cout << "The equation only has one root" << endl;
      }
    }
};

int main() {
  float a,b,c;
  cout << "Enter values for a, b, and c: ";
  cin >> a >> b >> c;

  QuadraticEquation test(a,b,c);
  if(test.getDiscriminant() > 0) {
    cout << "root1 = " << test.getRoot1() << " root2 = " << test.getRoot2() << endl;
  } else if(test.getDiscriminant() == 0) {
    cout << "root1 = " << test.getRoot1() << endl;
  } else {
    cout << "Equation has no roots" << endl;
  }
}
