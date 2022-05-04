#include <string.h>
#include "utils.h"
#include<stdio.h>

int validateOctalValue(char*octal_value) {

    /* Octal values can't have the value 8 and 9,
       so searches for them, if present
       it returns -1 */
    if((int)strcspn(octal_value, "89") != Strlen(octal_value)){
        return -1;
    }

    return 0;
}

int validateHexValue(char*hex_value) {

    /* Hex values can't have values other than
       "123456789ABCDEF" */
    if((int)strspn(hex_value, "0123456789ABCDEFabcdef \n") != Strlen(hex_value)){
        puts(hex_value);
        return -1;
    }

    return 0;
}

int validateIntValue(char*int_value) {

    for (int i = 0; int_value[i] != '\0'; i++){
        if(int_value[i] == ' ' || int_value[i] == '\n')
            continue;

        if (!isDigit(int_value[i])){
            return -1;
        }
    }

    return 0;
}

int validateBinValue(char*bin_value) {

    /* Binary values can't have values other 
       than 0 and 1 */
    for(int i = 0; i < Strlen(bin_value); ++i){

        if(*(bin_value+i) != 48 && *(bin_value+i) != 49){
            return -1;
        }
    }

    if(binToDec(bin_value) > 126){
        return -2;}

    return 0;
}
