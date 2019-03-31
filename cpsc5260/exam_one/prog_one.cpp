#include <iostream>
#include <cstdio>
#include <omp.h>
#include <vector>
using namespace std;

int main() {
  int sum = 0;
  vector < int > array (11000 , 1);

  #pragma omp parallel default(none) shared(array, sum)
  {
    int rank = omp_get_thread_num ();
    int nt = omp_get_num_threads ();
    int size = array.size();
    int count = size / nt;
    int start = rank * count;
    int mod = size % nt;

    if(rank < mod) {
      count ++;
      start += rank;
    } else {
      start += mod;
    }

    int localsum = 0;
    for (int i = start; i < start + count; i++) {
      // #pragma omp atomic
      localsum += array[i];
    }
#pragma omp barrier
  sum += localsum;
  }

  printf("total: %d\n", sum);
}
