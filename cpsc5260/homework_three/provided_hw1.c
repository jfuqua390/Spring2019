/* compile with: gcc -Wall -O3 provided_hw1.c -lm */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <omp.h>


void random_array(double* array, int size, double scale)
{
  # pragma omp parallel for
    for (int i=0; i<size; i++)
    {
        array[i] = (rand()*1.0/RAND_MAX) * scale;
    }

}


double sum(double* array, int size)
{
    int sum = 0;
    #pragma omp parallel for reduction(+:sum)
      for (int i=0; i<size; i++)
      {
          sum += array[i];
      }
    return sum;
}

double stdev(double* array, int size)
{
    double avg = sum(array, size) / size;
    double tot=0;

    #pragma omp parallel for reduction(+:tot)
      for (int i=0; i<size; i++)
      {
          tot += (array[i]-avg)*(array[i]-avg);
      }

    return sqrt(tot/size);
}


void smooth(double* array, int size, double w)
{
    double* scratch = malloc(size * sizeof(double));

    //can't parallelize
    for (int i=1; i<size-1; i++)
    {
        scratch[i] = array[i]*w + (array[i-1] + array[i+1])*(1.-w)/2.;
    }

    #pragma omp parallel for
      for (int i=1; i<size-1; i++)
      {
          array[i]=scratch[i];
      }

    free(scratch);
}



int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "usage: %s <size> <n_iter (optional)> <w (optional)>\n", argv[0]);
        exit(-1);
    }

    int size= atoi(argv[1]);

    if (size <= 0)
    {
        fprintf(stderr, "invalid size: %d\n", size);
        exit(-1);
    }

    double w = 0.8;
    int n_iter=10;

    if (argc > 2)
    {
        n_iter = atoi(argv[2]);
    }

    if (n_iter < 0)
    {
        fprintf(stderr, "invalid n_iter: %d\n", n_iter);
        exit(-1);
    }


    if (argc > 3)
    {
        w = atof(argv[3]);
    }

    if (w < 0 || w > 1.0)
    {
        fprintf(stderr, "invalid w: %lf\n", w);
        exit(-1);
    }

    double start = omp_get_wtime();

    double* array = malloc(size * sizeof(double));

    srand(getpid() ^ time(NULL)); /* unique seed for the random number generator */

    random_array(array, size, 10.0);

    /* this to force the stdev lower (smoothing should ultimately
    * zero out all the array contents) */
#ifdef FORCE_TO_ZERO
    array[0]=0;
    array[size-1]=0;
#endif

    double sd=stdev(array, size);

    printf("initial stdev: %lf\n", sd);

    // Don't think I can parallelize this for loop because the smoothing relies on the previous smoothing
    // #pragma omp parallel for
      for (int i=0; i<n_iter; i++)
      {
          smooth(array, size, w);

          sd = stdev(array, size);

          printf("iteration %d, stdev: %lf\n", i, sd);
      }

    double end = omp_get_wtime();
    printf("took % lf to smooth %d elements on %d threads\n " ,
      (end - start), size, omp_get_max_threads());

    free(array);
    return 0;
}
