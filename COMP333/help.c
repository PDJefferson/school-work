#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *convertNumb(int numbToConvert)
{
    int arabic[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char roman[13][3] = {"M\0", "CM\0", "D\0", "CD\0", "C\0", "XC\0", "L\0", "XL\0", "X\0", "IX\0", "V\0", "IV\0", "I\0"};

    char *romNumb = malloc(10 * sizeof(char));
    
    for (int i = 0; i < 13; i++) 
    {
    while (numbToConvert >= arabic[i]) 
        {
        strcat(romNumb, roman[i]);
        numbToConvert -= arabic[i];
        }
    }

    return romNumb;
}

char **code2(int *arabNumb, int size)
{
   char **romNumb = malloc(10 *  sizeof(char));
    for (int i = 0; i < size; i++)
    {
        romNumb[i] = malloc(10 *  sizeof(char));
    }
    int i;
    #pragma omp parallel master private(i) shared (romNumb, arabNumb) 
    {
    for ( i = 0; i < size; i++)
        {
        #pragma omp task
            {
            romNumb[i] = convertNumb(arabNumb[i]);
            }
        }
        #pragma omp taskwait
    }
return romNumb;
}

int main()
{
    int arrayOfNum[] = {1, 2, 3, 4, 5};
    size_t n = sizeof(arrayOfNum)/sizeof(*arrayOfNum);
    char **romanNumb = code2(arrayOfNum, n);
    {
        for (int i = 0; i < n; i++)
        {
            printf("%s\n", romanNumb[i]);
        }
    }
    return 0;
}