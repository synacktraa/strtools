#include<stdio.h>
#include <string.h>
#include"toString_utils.h"

int octToDec(int n){
   int dec = 0, oct = n, remain, count = 0, octPow;

   while(oct){ 
      count++; 
      oct = oct/10; 
   }
   oct = n; 
   for(int i = 0; i <= count; i++){
      remain = oct % 10; 
      octPow = power(8, i); 
      dec += remain * octPow; 
      oct = oct/10; 
   }
   return dec;

}


int* octal_to_string(char *octaldump){

    char *token;
    
    token = strtok(octaldump, " ");
    
    while( token != NULL ) {
        printf("%c", octToDec(AtoI(token)));
        token = strtok(NULL, " ");
    }

    return 0;
}


int* decimal_to_string(char *decimal_dump){

    char *token;
    
    token = strtok(decimal_dump, " ");
    
    while( token != NULL ) {
        printf("%c", AtoI(token));
        token = strtok(NULL, " ");
    }

    return 0;
}


int main(int argc, char**argv){

    decimal_to_string(argv[1]);
    return 0;
}