#include <omp.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char **argv)
{
int nThreads, tid;
omp_set_num_threads(4);
#pragma omp parallel private(nThreads,tid)
{
    tid= omp_get_thread_num();
    printf("Hello World from thread %d\n",tid);
}
 
 return 0;  
}
