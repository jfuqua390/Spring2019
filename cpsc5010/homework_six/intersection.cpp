#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

#define point pair<double, double>

void displayPoint(point p) {
  cout << "(" << p.first << ", " << p.second << ")" << endl;
}

point linesIntersection(point a, point b, point c, point d) {
  //first line a1x + b1y = c1
  double a1 = b.second - a.second;
  double b1 = a.first - b.first;
  double c1 = a1*(a.first) + b1*(a.second);

  //second line a2x + b2y = c2
  double a2 = d.second - c.second;
  double b2 = c.first - d.first;
  double c2 = a2*(c.first) + b2*(c.second);

  double determinant = a1*b2 - a2*b1;

  if(determinant == 0) {
    return make_pair(INT8_MAX , INT8_MAX);
  } else {
    double x = (b2*c1 - b1*c2) / determinant;
    double y = (a1*c2 - a2*c1) / determinant;
    return make_pair(x, y);
  }
}

int main() {
  double x1,x2,x3,x4,y1,y2,y3,y4;
  cout << "Enter four endpoints x1, y1, x2, y2: ";
  cin >> x1 >> y1 >> x2 >> y2;
  cout << "Enter four endpoints for second line x3 , y3, x4, y4: ";
  cin >> x3 >> y3 >> x4 >> y4;

  point a = make_pair(x1,y1);
  point b = make_pair(x2,y2);
  point c = make_pair(x3,y3);
  point d = make_pair(x4,y4);

  point intersection = linesIntersection(a,b,c,d);

  if(intersection.first == INT8_MAX && intersection.second == INT8_MAX) {
    cout << "Lines are parallel" << endl;
  } else {
    cout << "Intersecting point is: ";
    displayPoint(intersection);
  }

  return 0;
}
