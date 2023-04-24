#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mySpecialFunction(int* input, int arraysize);
int question(int*, int n);
int main(int argc, char **argv)
{

  int n = 200;
  int test[200];

      for(int i = 0; i< n;i++)
        test[i] = i;

  printf("%d\n",
         question(test, n));

 

 return 0;  
}


int mySpecialFunction(int* input, int arraysize){
    int i; 
    int maxVal = 0;
 #pragma omp parallel for private(i) reduction(max:maxVal)
    for(i=0; i<arraysize; i++){
      if(input[i]>maxVal){
          maxVal= input[i];
      }
    }
    return maxVal;
}

  int question(int in[], int n){
      int count = 0;
      int sum = 7;
      int* evenAr;

    #pragma omp parallel for reduction(+:count) shared(evenAr,in)
        for (int i = 0; i < n; i++)
        {
          if (in[i] % 2 == 0)
            count++;
        }

        evenAr = (int*)calloc(count, sizeof(int));

        count = 0;
        for (int i = 0; i < n; i++)
        {
          if (in[i] % 2 == 0)
          {
            evenAr[count] = (in[i] / n) % 2;
            printf("%d value %d \n ", count, evenAr[i]);
            count++;
          }
        }
      

    #pragma omp parallel for reduction (+ : sum) shared(evenAr,n,count)
       
        
        for (int i = 0; i < count; i++){
          sum +=  evenAr[i];
          printf("%d evenAr at %d \n " ,i, evenAr[i]);
        }
      free(evenAr);
      return sum;
  }
