#include <cstdio>
#include <omp.h>
#include <vector>


int main(int argc, char *argv[])
{
    int size=1000000;
    std::vector<int> array(size, 1);
    int sum=0;

    double starttime = omp_get_wtime();
#pragma omp parallel
    {
        int rank = omp_get_thread_num();
        int nt = omp_get_num_threads();
        printf("%d threads\n", nt);

        int count = size / nt;
        int start = rank * count;
        int mod = size % nt;

        // tweak partitions when size not divisible by nt
        if (rank < mod)
        {
            count++;
            start += rank;
        }
        else
        {
            start += mod;
        }

        int localsum=0;

        for (int i=start; i<start+count; i++)
        {

                localsum += array[i];
        }

// #pragma omp critical -- too slow
#pragma omp atomic
        sum += localsum;


        printf("%d finished: %d\n", rank, sum);
    }
    double endtime = omp_get_wtime();


    printf("final answer: %d - %lf\n", sum, (endtime-starttime));


    return 0;
}
