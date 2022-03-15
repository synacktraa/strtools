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

int hexToDec(char* h){ 

    int dec = 0, bitshift = 0, cnt = 0;
    char* ptr = h; 
    
    auto int decimal(int,int,int); 
    int decimal(int bit, int count, int minValue){ 

        int num = 0, hexPow = 0;
        hexPow = power(16, bit); 
        num += (*(h+count)-minValue)*hexPow;
        return num; 
    } 
    while(*ptr != '\0'){ 
        cnt++; 
        ptr++; 
    }
    while(cnt >= 0){ 
        --cnt;
        if((*(h+cnt) >=97 && *(h+cnt) <=102)) 
            dec += decimal(bitshift, cnt, 87); 
        else if((*(h+cnt) >=65 && *(h+cnt) <=70)) 
            dec += decimal(bitshift, cnt, 55); 
        else if((*(h+cnt) >=48 && *(h+cnt) <=57)) 
            dec += decimal(bitshift, cnt, 48); 
        bitshift++; 
    }
    return dec;
}


int binToDec(char* binary){ 
    
    int i = 0, j, k;
    int dec = 0;
    while(*(binary+i) != '\0')
        ++i;

    for(j = i-1, k = 0; j >= 0; --j, ++k)
        dec += (*(binary+k)-48)*power(2,j); 

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

int* binary_to_string(char *bindump){

    char *token;
    
    token = strtok(bindump, " ");
    
    while( token != NULL ) {
        printf("%c", binToDec(token));
        token = strtok(NULL, " ");
    }

    return 0;
}


int main(int argc, char**argv){

    binary_to_string(argv[1]);
    return 0;
}