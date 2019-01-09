#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

void random_array(double* array, int size, double scale) {
  srand(time(0));
  //generate array
  for(int i=0; i<size; i++) {
    double r = rand() % 9999;
    r *= .0001;
    array[i] = r * scale;
  }
}

void sort_array(double* array, int size) {
  for(int i=0;i<size; i++) {
    for(int j=i+1; j < size; j++) {
      if(array[i] > array[j]) {
        double n = array[i];
        array[i] = array[j];
        array[j] = n;
      }
    }
  }
}

double sum(double* array, int size) {
  double total;
  for(int i=0; i < size; i++) {
    total += array[i];
  }
  return total;
}

double stdev(double* array, int size) {
  double mean = sum(array, size)/size;
  double diffs[size];

  for(int i=0; i<size; i++) {
    double diff = array[i] - mean;
    diffs[i] = diff*diff;
  }
  double variance = sum(diffs,size)/size;
  return sqrt(variance);
}

void smooth(double* array, int size, double w) {
  for(int i=1; i<size-1; i++) {
    double newVal = array[i]*w + ((array[i-1] + array[i+1])*(1-w)/2);
    printf("OldVal=%f, NewVal=%f\n", array[i], newVal);
    array[i] = newVal;
  }
}
