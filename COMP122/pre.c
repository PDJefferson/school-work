#include <stdio.h>
#include <String.h>
#include <math.h>
#include <stdlib.h>
int a[9] = {1,2,3,4,5,635,64,7,8};

int calculateAverage (int* input, int size)
{
         int i =0;
         int n =0;
         for(i = 0; i < size; i += 1)
         {
                 n+= input[i];
         }
         return n/size;
}
int main (int argc, char * argv[])
{
         printf(" The Average is %d", calculateAverage(a,9));

         return 0;
}