#include <stdio.h>
#include <String.h>
#include <math.h>
#include <stdlib.h>
int getUserInput();
double project3recursive(int n);

int main(int argc, char * argv[]){
    double check;
    int n = getUserInput();
    check = project3recursive(n);
    printf("%f" , check);
    return 0;
}
int getUserInput(){
    int result;
    printf("Enter a decimal value \n");
    scanf("%d", &result);
    return result;
}
double project3recursive(int n){

    if (n == 0){

        return 1;
    }

    else{

        return project3recursive (n-1)* ((4.0/(n*n*n))+ (31*n*n)- (2*n));

    }

}

