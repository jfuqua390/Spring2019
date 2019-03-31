#include <iostream>
#include <cstdio>
#include <omp.h>
#include <vector>

// replace the contents of data with the prefix sum of the contents
void prefix_sum ( std :: vector < int >& data )
{
  int sum = 0;
  # pragma omp parallel default ( none ) shared ( data, sum )
  {
    int rank = omp_get_thread_num ();
    int nt = omp_get_num_threads ();
    // Your code goes here .
    int size = data.size();
    int count = size / nt;
    int start = rank * count;
    int mod = size % nt;

    if(rank < mod) {
      count ++;
      start += rank;
    } else {
      start += mod;
    }
    int end = start + count;
    printf("My Count: %d, t=%d, s=%d, e=%d \n", count, rank, start, end);

    int localsum = 0;

    for(int i = start; i < start + count; i++) {
      localsum += data[i];
    }

// #pragma omp atomic
//   sum += localsum;
#pragma omp barrier
  sum += localsum;

    printf("%d finished: %d\n", rank, sum);
  }

  printf("%d is the final sum\n", sum);
}

int main ( int argc , char * argv [])
{
  // test with a vector of 1’ s
  std :: vector < int > data (11000 , 1);

  double start = omp_get_wtime ();
  prefix_sum ( data );
  double end = omp_get_wtime ();

  printf ( " took % lf to prefix sum %d elements on % d\n " ,
    ( end - start ), ( int ) data . size () , omp_get_max_threads ());
}
