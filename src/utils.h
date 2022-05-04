
#pragma once


//Function declarations
int octToDec(int oct);
int hexToDec(char* hex);
int binToDec(char* bin);
int power(int base, int exp);
int isDigit(int ch);
int Strlen(char *str);
int AtoI(const char* str);
void reverse(char*str);
void ItoA(int dec, char* dest);
char* decToHex(int n);
int decToOct(int n);
char* decToBin(int n);
void freeIt(char* alloc_mem);


