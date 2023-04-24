#include <stdio.h>
#include <String.h>
#include <math.h>
#include <stdlib.h>
int theArray[40];

int main(int argc, char * argv[]) {
         int n = 2;
         theArray[0] = 1;
         theArray[1] = 1;
         do {
                 theArray[n] = theArray[n-1] + theArray[n-2];
                 n += 1;
                 printf("%d\n", n);
                 
                 } while (n < 40);

for(int i =0; i < 40 ; i++){
             printf("%d\n", theArray[i]);
             }
            
         return 0;

         
}