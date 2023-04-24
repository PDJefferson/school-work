#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
static long numSteps = 100000;
double step;
void main(){
    int i;
    double x, pi, sum= 0.0;

    step= 1.0/(double)numSteps;
    #pragma omp parallel for reduction(+:sum) private(x,i,step)
        for(i =0 ; i< numSteps;i++){
            printf("Thread being used %d \n" , omp_get_thread_num());
            x = (i+0.5)*step;
            sum += (4.0/(1.0+x*x));
            printf("value of sum %f \n", sum);
        }      

    pi= step*sum;

    printf("%f",pi);
}