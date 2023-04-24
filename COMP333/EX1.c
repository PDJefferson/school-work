#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void prp4();
void tracingQuestionTask();
void otherTracingFunctionTask();
int** idM(int);
void testIDM(int m);
int fib(int );
void testFIB(int);
void testArray();
int* prob02(int* array,int);


int main(int argc, char* argv[]){
    // prp4();
    // tracingQuestionTask();
    // otherTracingFunctionTask();
    // testIDM(5);
    testFIB(9);
    
    testArray();

    return 0;
}

    void testArray(){
    int temp[13] = {1,2,4,6,8,10,12,14,18,19,21,24,26};
    int size = sizeof(temp)/sizeof(temp[0]);
    printf("\n size of array before %d \n ", size);
    int* r = prob02(temp,size);
    for (int i = 0; i < 13 ; i++){
        printf("value at %2d is : %2d \n" , i, r[i]);
    }
    
    free(r);

    }
void prp4(){
    int tid,nthreads;
    #pragma omp parallel private(nthreads, tid)
  {
      tid = omp_get_thread_num();
      printf("hello world from just parallel = %d\n", tid);
  }
}

void tracingQuestionTask(){
    int nThreads,tid;
    int i;
    #pragma omp parallel master private(i)
    {
        for(i=0 ; i < omp_get_num_threads();i++){
            //take a copy of I and assign a value to each task
            #pragma omp task firstprivate(i)
            {
                 printf("hello world from task= %d %4d\n",i, omp_get_thread_num());

            }
            #pragma omp taskwait
        }
    }
}
void otherTracingFunctionTask(){
    int i, a[4];
    #pragma omp parallel master private(i)
    {
        for(int i = 0; i < 4; i++){
            #pragma omp task firstprivate(i)
            {
                printf("%d %d \n ", i, omp_get_thread_num() );
            }
            #pragma omp taskwait
        }
    }
}

void testIDM(int m){
    int i,j;
    int** test = idM(m);
    for(i =0 ; i< m;i++){
        for(j= 0 ;j  <m ;j++){
            printf("%4d ", test[i][j]);
        }
        printf("\n");
    }
    free(test);
}

int** idM(int n){
    int ** result = (int**)malloc(sizeof(int*)*n);
    int i;
    #pragma  omp parallel master private(i)
    { 
        for(i=0; i < n; i++){
            #pragma omp task firstprivate(i)
            {
                result[i] = (int*) calloc(sizeof(int),n);
                result[i][i] =1;
            }
        }
        #pragma omp taskwait

    }
    return result;
}

void testFIB(int m){
   printf("value of fib %d", fib(m));
}


int fib(int n)
{

  int f[n+2];  
  int i;
 
  // 0th and 1st number of the series are 0 and 1
  f[0] = 0;
  f[1] = 1;
 #pragma omp parallel master private(i)
 {
  for (i = 2; i <= n; i++)
  {
      #pragma omp task firstprivate(i)
      f[i] = f[i-1] + f[i-2];
      #pragma omp taskwait
  }
    
 }
 
  return f[n];
}


 int* prob02(int* array, int n) {
 		int* ans = (int*) calloc(sizeof(int),n);
         int i;
         int j;
 		#pragma omp parallel master private(i,j)
        {
            for(i =0 ; i < n; i++) {
               #pragma omp task firstprivate(i)
               {
                   for(j = i ; j < n; j++ ){   
                    ans[i] += array[i]; 
                    } 
               }
            }
            #pragma omp taskwait
        }
		return ans;
	}


