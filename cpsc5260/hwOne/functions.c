#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

void randomize_array(double* array, int size, double scale) {
  srand(time(0));
  //generate array
  int i=0;
  for(i=0; i<size; i++) {
    double r = rand() % 9999;
    r *= .0001;
    array[i] = r * scale;
  }
}

double sum(double* array, int size) {
  double total = 0;
  int i = 0;
  for(i=0; i < size; i++) {
    total += array[i];
  }
  return total;
}

double stdev(double* array, int size) {
  double mean = sum(array, size)/size;
  double *differences_array;
  differences_array = malloc(sizeof(double) * size);

  int i = 0;
  for(i=0; i<size; i++) {
    double diff = array[i] - mean;
    differences_array[i] = diff*diff;
  }
  double variance = sum(differences_array, size) / size;
  return sqrt(variance);
}

void smooth(double* array, int size, double w) {
  double *smooth_array;
  smooth_array = malloc(sizeof(double) * size);

  int i = 0;
  for(i=1; i < size - 1; i++) {
    double newVal = array[i] * w + ((array[i-1] + array[i+1]) / 2) * (1 - w);
    smooth_array[i] = newVal;
  }

  for(i=1; i < size-1; i++) {
    array[i] = smooth_array[i];
  }
}

void print_array(double* array, int size) {
	int i = 0;

	for(i = 0; i < size; i++) {
		printf("Val: %0.2f\n", array[i]);
	}

	printf("\n");
}
