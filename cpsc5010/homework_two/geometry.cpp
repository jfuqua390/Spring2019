#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

/*
(Geometry: two circles) Write a program that prompts the user to enter the center coordinates and radii of two circles and
determines whether the second circle is inside the first or overlaps with the first, as shown in Figure 3.12.
(Hint: circle2 is inside circle1 if the distance between the two centers <= |r1 - r2| and
circle2 overlaps circle1 if the distance between the two centers <= r1 + r2. Test your program to cover all cases.)

1,1,5,5,5,3
0,0,10,1,1,3
-5,0,3,5,0,3
*/

int main() {
  float circle_1_x, circle_1_y, circle_1_radius, circle_2_x, circle_2_y, circle_2_radius, distance;
  cout << "Enter x, y and radius for circle one: " << endl;
  cin >> circle_1_x >> circle_1_y >> circle_1_radius;
  cout << "Enter x, y, and radius for circle two: " << endl;
  cin >> circle_2_x >> circle_2_y >> circle_2_radius;

  distance = sqrt(((circle_2_x - circle_1_x)*(circle_2_x - circle_1_x)) + ((circle_2_y - circle_1_y) * (circle_2_y - circle_1_y)));
  cout << "Distance: " << distance << endl;
  //inside
  if(distance <= abs(circle_1_radius - circle_2_radius)) {
    cout << "Circle 2 is inside Circle 1" << endl;
  } else if(distance <= circle_1_radius + circle_2_radius) {
    cout << "Circle 2 overlaps Circle 1" << endl;
  } else {
    cout << "The circles don't touch" << endl;
  }
}
