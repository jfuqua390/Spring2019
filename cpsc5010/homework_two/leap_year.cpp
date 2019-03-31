#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

//Write a program that displays all the leap years, ten per line, in the twenty-first century (from 2001 to 2100), separated by exactly one space.

int main() {
  int a = 2001;
  int b = 2100;
  int c = 10;
  int count = 0;

  for(int i = a; i <= b; i++) {
    if((i % 4 == 0 && i % 100 !=0) || (i % 400 == 0)) {
      cout << i << " ";
      count ++;
      if(count % 10 == 0) {
        cout << endl;
      }
    }
  }
  cout << endl;
}
