#include <iostream>
#include <string>
using namespace std;

void drawLowRightTriMulTable(int n) {
  for(int row = 1; row <= n; row++) {
    for(int col = 0; col < n - row; col++) {
      cout << " ";
    }
    for(int col = n - row + 1; col <= n; col++) {
      cout << row * col << " ";
    }
    cout << endl;
  }
}

int main() {
  int size;
  cout << "Input the size of the table: " << endl;
  cin >> size;
  drawLowRightTriMulTable(size);
}
