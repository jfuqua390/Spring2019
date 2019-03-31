#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

class Circle2D {
  private:
    //data fields
    double x,y,radius;
    const double pi = 3.14159265358979323846;


  public:
    //returns x
    double getX() {
      return x;
    }

    //returns y
    double getY() {
      return y;
    }

    //Returns radius
    double getRadius() {
      return radius;
    }

    //default constructor, creates circle at (0,0) and radius = 1
    Circle2D() {
      x = 0;
      y = 0;
      radius = 1;
    }

    //Constructor to create a circle with specified parameters
    Circle2D(double _x, double _y, double _radius) {
      x = _x;
      y = _y;
      radius = _radius;
    }

    //returns the area of the Circle2D
    double getArea() {
      return pi * radius * radius;
    }

    //returns the perimeter of the Circle2D
    double getPerimeter() {
      return 2 * pi * radius;
    }

    bool contains(double _x, double _y) {
      return sqrt(((_x - x) * (_x - x)) + ((_y - y) * (_y - y))) < radius;
    }

    bool contains(Circle2D circle) {
      return sqrt(((circle.getX() - x) * (circle.getX() - x)) +
                  ((circle.getY() - y) * (circle.getY() - y))) <= abs(radius - circle.getRadius());
    }

    bool overlaps(Circle2D circle) {
      return sqrt(((circle.getX() - x) * (circle.getX() - x)) +
                  ((circle.getY() - y) * (circle.getY() - y))) <= abs(radius + circle.getRadius());
    }
};


int main() {
  Circle2D c1(2,2,5.5);
  Circle2D c2(4,5,10.5);
  Circle2D c3(3,5,2.3);
  cout << "Area: " << c1.getArea() << endl;
  cout << "Perimeter: " << c1.getPerimeter() << endl;
  cout << "First test: " << c1.contains(3,3) << endl;
  cout << "Second test: " << c1.contains(c2) << endl;
  cout << "Third test: " << c1.overlaps(c3) << endl;

  return 0;
}
