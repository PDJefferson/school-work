#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char *argv[]) 
{
    printf("check");
    int n =1000000;
int nthreads, tid, tstart, tend,i, count;
float a[n], sum, psum;
 


for (i=0; i < n; i+=1)
  a[i] = i * 1.0;


  sum =0;

  #pragma omp parallel for private(i)   
  
  for (i=0; i < n; i+= 1)
  #pragma omp critical
    sum += a[i]; 
  


  sum =0;
  
  #pragma omp parallel for private(i)   
  
  for (i=0; i < n; i+= 1)
  #pragma omp atomic
    sum += a[i]; 



sum = 0;

#pragma omp parallel shared(a,nthreads,sum) private(i,tid,psum, tstart, tend)
  {
  tid = omp_get_thread_num();
  nthreads = omp_get_num_threads();

  psum = 0;
  count=0;
  tstart = tid * (int) ceil(((double)n/nthreads));
  tend =  (tid +1) * (int)ceil(((double)n/nthreads));
  if (tend < n)
  {
    for (i = tstart; i < tend ; i+=1)
      psum += a[i];
  }
  else
  {
    for (i = tstart; i < n; i+=1)
    psum += a[i];
  }

  //printf("The partial sum is: %f in thread %d \n", psum, tid); 
  #pragma omp critical
    sum += psum;
}
 printf("%d \n",sum);
    return 0;
}