#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int size = 10;
  double scale = 10;
  double w = .40;

  double *random_array;
  random_array = malloc(sizeof(double) * size);

  //Create array and run first sum and stddev
  randomize_array(random_array, size, scale);
  double sum_1 = sum(random_array, size);
  double stddev_1 = stdev(random_array,size);
  smooth(random_array, size, w);
  double stddev_2 = stdev(random_array, size);
  smooth(random_array, size, w);
  smooth(random_array, size, w);
  smooth(random_array, size, w);
  smooth(random_array, size, w);
  double stddev_3 = stdev(random_array, size);

  printf("value of sum : %f \n", sum_1);
  printf("value of stddev : %f \n", stddev_1);
  printf("value of stddev2 : %f \n", stddev_2);
  printf("value of stddev_3 : %f \n", stddev_3);

  return 0;
}
