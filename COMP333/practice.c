#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
char roman[13][3] = {"M\0", "CM\0", "D\0", "CD\0", "C\0", "XC\0", "L\0", "XL\0", "X\0", "IX\0", "V\0", "IV\0", "I\0"};
int arabic[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
void printArray();
double implementFunction2(int);
double implementFunction(int);
char* convertArabic( int , int, int);
double implementQuestion2(int n);

int main(int argc, char **argv)
{
    printf("%lf\n",implementQuestion2(10));
    int n;
    int arabicSize = sizeof(arabic)/sizeof(arabic[0]);
    int romanSize = sizeof(roman)/sizeof(roman[0][0]);
    char* result;
    printf("%d\n" , romanSize);
    printf("Enter arabic number: \n");
    scanf("%d", &n);
    printf("\nRoman Number\n");
    
    result =  convertArabic(arabicSize,romanSize,n);

        for(int i =0; i< arabicSize; i++){
        printf("%c", result[i]);
        }
    

    return 0;
}

void printArray(){
    int i;
    for(i=0;i<100;i++){
        printf("values are %d \n" , i);
    }
}
double implementFunction(int n){
    int i;
    double sum;
    #pragma omp parallel for reduction(+:sum) private(i)
        for(i =1; i<=n; i++){
            sum+= (double)((n/i)); 
        }
    
    return sum;
}
double implementFunction2(int n){
    double sum;
    int i;
    #pragma omp parallel for reduction(+: sum) private(i)
    
        
        for(i =1; i <= n ; i++){
            sum += (double)((3.0/i) + (i/21.0));
        }
    
    return sum;
}

char* convertArabic( int arabicSize, int romanSize,int n){
    int i;
    char* result= (char*)calloc(sizeof(char*),arabicSize);
    #pragma omp parallel private(i)
    {
        #pragma omp master
        {
            for(i =0; i< 13 ;i++){
                #pragma omp task firstprivate(i)
                {
                    while(n>=arabic[i]){
                        strcat(result,roman[i]);
                        n-= arabic[i];
                    }
                }
                #pragma omp taskwait
            }
        }
    }
    return result;

}

double implementQuestion2(int n){
    int i;
    double sum;

    #pragma omp parallel for reduction(+:sum) private(i)
        for(i = 1; i <= n; i+=1){
            double it = i;
            sum += (double)((n/it)+(it/n));
             printf("%lf\n", sum);
        }
    return sum;    
} 