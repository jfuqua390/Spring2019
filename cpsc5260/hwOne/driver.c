#include "functions.h"
#include <stdio.h>

int main() {
  int size = 50;
  double scale = 30;
  double arrayRando[size];
  double w = .90;

  random_array(arrayRando, size, scale);
  sort_array(arrayRando, size);
  for(int i=0; i<size; i++) {
    printf("arr[%d]=%f \n", i, arrayRando[i]);
  }
  double sumo = sum(arrayRando, size);
  double stddev = stdev(arrayRando,size);
  smooth(arrayRando, size, w);
  double stddev2 = stdev(arrayRando, size);
  printf("value of sum : %f \n", sumo);
  printf("value of stddev : %f \n", stddev);
  printf("value of stddev2 : %f \n", stddev2);
  return 0;
}
