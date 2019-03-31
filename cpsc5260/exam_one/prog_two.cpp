#include <iostream>
#include <cstdio>
#include <omp.h>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  int size = 50000;
  vector<double> values(size, 1);
  vector<double> array(size, 0);

  for(int i = 1; i < size; i++) {
    values[i] = values[i] + values[i-1];
  }

  for(int i = 0; i < size; i++) {
    for(int j=0; j < array[i]; j++) {
      array[i] += sqrt(j)*(i-j);
    }
  }
}
