#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

class Location {
public:
  int row, column;
  double maxValue;

  Location(int row, int col, double value) {
    row = row;
    column = col;
    maxValue = value;
  }
};

Location locateLargest(double a[4][2], int n, int m) {
  double max = a[0][0];
  Location loc(0,0,max);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(a[i][j] > max) {
        loc.row = i;
        loc.column = j;
        loc.maxValue = a[i][j];
        max = a[i][j];
      }
    }
  }
  return loc;
}

int main() {
  double arr[4][2] = {
    {1,2},
    {3,4},
    {5,6},
    {3,3}
  };
  Location test = locateLargest(arr, 4, 2);
  cout << "Location row: " << test.row << " Location column: " << test.column << " Location max value: " << test.maxValue << endl;
}
