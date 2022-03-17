#ifndef UTILS_H /* Include guard */
#define UTILS_H

//Function declarations
int power(int base, int p);
int Strlen(const char* string);
void Strcpy(char* dest, char* src);
int Strncut(char* dest, char* src, int ncut);
int Strdcut(char*dest, char* src, char delimeter);
int Strcmp(const char* string1, const char* string2);
void Strcat(char* string1, const char* string2);
char* Charcat(char* string, char character);
int delete(char*data, int index, int length);
void reverse(char*str);
int isDigit(int ch);
int AtoI(const char* str);
void ItoA(int dec, char*str);
void memreset(char* string, int u_size);

#endif