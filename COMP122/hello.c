#include <stdio.h>
#include <String.h>
#include <math.h>
#include <stdlib.h>
int fun(int firstValue,int secondValue, int thirdValue);


int main(int argc, char * argv[]){
    int firstValue = 2; 
    int secondValue =6; 
    int thirdValue = 3; 
   
    printf("%d", fun(firstValue,secondValue,thirdValue));
    return 0;
}

int fun(int firstValue,int secondValue, int thirdValue){
    int result;
    result =  secondValue * pow(2,10);
    result += firstValue;
    result *= thirdValue;
    
   
    return result;

}