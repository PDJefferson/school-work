#include <stdio.h>

void printAnswer(int numbers[], int size);
void swap(int* a, int* b);
int partition (int numbers[], int low, int high);
void quickSort(int numbers[], int low, int high);

int main(int argc, char * argv[]){
 
    int numbers[] = {1, 23, 45, 10, 8, 99, 32, 17, 54, 73, 3, 89}; 
    int size= sizeof(numbers)/sizeof(numbers[0]); 
    quickSort(numbers, 0, size-1); 
    printf("Sort using quicksort: \n"); 
    printAnswer(numbers, size); 
    
    return 0;
}

void printAnswer(int numbers[],int size){ 

    int i; 
    for (i=0; i < size; i++){
        printf("%d ", numbers[i]);
    } 
    printf("\n"); 
} 


void swap(int* valueAtI, int* valueAtJ){ 
 
    int temp = *valueAtI; 
    *valueAtI = *valueAtJ; 
    *valueAtJ = temp; 
} 

int partition (int numbers[], int low, int high){
 
    int pivot = numbers[high];   
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++){ 
    
        if (numbers[j] < pivot) {
            i++;    
            swap(&numbers[i], &numbers[j]); 
        } 
    } 
    swap(&numbers[i + 1], &numbers[high]); 
    return (i + 1); 
} 
  

void quickSort(int numbers[], int low, int high){

    if (low < high){
     
        int pi = partition(numbers, low, high); 
  
        quickSort(numbers, low, pi - 1); 
        quickSort(numbers, pi + 1, high); 
    } 
} 
  


  