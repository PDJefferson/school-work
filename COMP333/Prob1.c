#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
void printArray();
int mathRands[100];

int main(int argc, char **argv)
{
 int i;

 #pragma omp parallel for private(i)
   for(i=0;i< 100; i++){
       mathRands[i] = rand();
   } 
 
 printArray();
 
 return 0;  
}

void printArray(){
    int i;
    for(i=0;i<100;i++){
        printf("values are %d \n" , mathRands[i]);
    }
}