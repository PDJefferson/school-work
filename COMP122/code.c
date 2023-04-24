#include <stdio.h>
#include <String.h>
#include <math.h>
#include <stdlib.h>

char *decimal_to_binary(int n);

int main(int argc, char * argv[]){
   int input=2;
   printf("%s",decimal_to_binary(600));
   
  return 0;
}

char *decimal_to_binary(int n)
{
   int c, d, count;
   char *pointer;
   
   count = 0;
   pointer = (char*)malloc(sizeof(char)*(int)((double)log10(n)/log10(2))+2);
   
  
   if (pointer == NULL)
      exit(EXIT_FAILURE);
     
   for (c = sizeof(pointer)/sizeof(pointer[0]) ; c >= 0 ; c--)
   {
      d = n >> c;
      printf("for d %d", d);
      printf("\ncount %d", count);
      if (d & 1)
         *(pointer+count) = 1 + '0';
      else
         *(pointer+count) = 0 + '0';
     
      count++;
      
   }
   
   *(pointer+count) = '\0';
   
   return  pointer;
}
 
