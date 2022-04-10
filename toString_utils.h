#ifndef CONVERT_H /* Include guard */
#define CONVERT_H

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

#endif
