#include <stdio.h>
#include <String.h>
#include <math.h>
#include <stdlib.h>

int getUserInput();
void printResults(int input);
char* decimalToOctal(int input);
char* decimalToHex(int input);
char* decimalToBinary(int input);
int hexToDecimal(char input);
char* loopHelper(int decimal,int c, char* result);
char* recursiveLoop(char answer,char* result, int decimal,int c,int d);

int myIndex;
//did not use this :_;
const char binHex[16][5] = 
    {"0000","0001","0010","0011",
    "0100","0101","0110","0111",
    "1000","1001","1010","1011",
    "1100","1101","1110","1111" };

int main(int argc, char * argv[]){
   int input;
   if(argc<2){
       input = getUserInput();
       printResults(input);
   }else{
       printResults((int)strtol(argv[1],NULL,10));
   }return 0;
}
int getUserInput(){
    int result;
    printf("Enter a decimal value \n");
    scanf("%d", &result);
    return result;
}


void printResults(int input){
    char* hex;
    char* octal;
    char* binary;
    hex = decimalToHex(input);
    octal = decimalToOctal(input);
    binary = decimalToBinary(input);
    printf("The value of %d in Hex is %s \n",input,hex);
    printf("The value of %d in Octal is %s \n",input,octal);
    printf("The value of %d in Binary is %s \n",input,binary);
    free(hex);
    free(octal);
    free(binary);
}

char* decimalToHex(int input){
    char* result;
    if(input ==0){
        return result = "0";
    }
    
    //the log  of the base + 2 
    result = (char*) malloc(sizeof(char)*(int)((double)log10(input)/log10(16))+2);
    sprintf(result, "%x",input);
    return result;
}

char* decimalToOctal(int input){
    char* result;
    if(input ==0){
        return result ="0";
    }
    result = (char*) malloc(sizeof(char)*(int)((double)log10(input)/log10(8))+2);
    sprintf(result,"%o", input);
    return result;
}
//not use this method either
int hexToDecimal(char input){
    if(input <='9' &&  input >= '0'){
        if(input <='f' && input >='a' ){
            if(input <=  'F' && input >='A'){
                return ((input -'A') +10);
            }
            return ((input -'a')+10);
        }
        return ((input - '0'));
    } 
    return 0;
}
char* decimalToBinary(int input){
    int i,tempDecimal;
    char *result;
    if(input ==0)return result = "0000";
    result= (char*)malloc(sizeof(char)*(int)((double)log10(input)/log10(2))+2);
    tempDecimal = input;  
    int c=sizeof(result)/sizeof(result[0]); 
    int d= tempDecimal >> c;
    myIndex = -1;
    loopHelper(tempDecimal,c, result);
    *(result+myIndex) = '\0';
    return  result;
}
     
 
    


char* loopHelper(int decimal,int c, char* result){
    char answer;
    int d;
    recursiveLoop(answer,result,decimal,c,d);
}

char* recursiveLoop(char answer,char* result, int decimal,int c,int d){
    d= decimal>>c;
    myIndex++;
    if(c == -1){
        return result;
    }else if(d & 1){
    recursiveLoop((*(result+myIndex)= (1 + '0')),result, decimal,(c-1),decimal >> c);
    }else{
    recursiveLoop((*(result+myIndex)= (0 + '0')),result, decimal,(c-1),decimal >> c);
    }
   
}




