
int power(int base, int p){ //this user defined function takes a number and power vaue and returns base^p
   int result = 1;
   if(p){ //if the value is not 0, it runs the statement below
      for(int i = p; i > 0; i--){ //i i set to p and condition checks if i is greater than 1 if yes...it runs the statement
      // in the for block which is base is multiplied by base until i is equal 1 
         result *= base;
      }
      return result;
   }
   else{ //if the value of p is 0
      return result; //returns 1
   }
}


int Strlen(const char* string){
    
    int len = 0;
    while (*string != '\0'){
        len++;
        string++;
    }
    return len;    
}


int delete(char*data, int index, int length){

    int i;
    for (i = index; i < (length)-1; i++)
    {
        *(data+i) = *(data+i+1);
    }
    *(data+i) = '\0';
    length--;
    return length;

}

int Strncut(char* destination, char* src, int ncut){
   
    int i, len;
   for(i = 0; i < ncut; i++){
        *(destination+i) = *src;
        len = delete(src, 0, Strlen(src));

    }
   *(destination+i) = '\0';
   
   return len;
   
}

int Strdcut(char*dest, char* src, char delimeter){

    int data_len = 0, cnt = 0;

    while(*(src+cnt) != delimeter)
        cnt++;
        
    data_len = Strncut(dest, src, cnt);
    data_len = delete(src, 0, data_len);

    return data_len;
}

int Strcmp(const char* string1, const char* string2){

   int len_string1 = Strlen(string1);
   int len_string2 = Strlen(string2);

   if((len_string1 - len_string2) == 0){
      for(int i = 0; i < len_string1; i++){
         if(*(string1+i) == *(string2+i))
            len_string2--;         
      }
      if(len_string2 == 0)
         return 0;
      else
         return 1;
   } else{
      return 1;
      }
}

void Strcat(char* string1, const char* string2){

   int i, j;

    for(i = Strlen(string1), j = 0;j < Strlen(string2); i++, j++)
        *(string1+i) = *(string2+j);            
    *(string1+i) = '\0';

}

char* Charcat(char* string, char character){

   int i;
   i = Strlen(string);
   *(string+i) = character;            
   *(string+i+1) = '\0';
   return string;

}

int isDigit(int ch){
   if(ch >= 48 && ch <= 57)
      return 1;
   return 0;
}

void reverse(char*str){
   
   int len = 0, temp;
   char*ptr = str;
   while(*ptr != '\0'){
      len++;
      ptr++;
   }
   int i = 0, j = len-1;
   while(i < j){
      temp  = *(str+i);
      *(str+i) = *(str+j);
      *(str+j) = temp;
      ++i;
      --j;
   }
}


int AtoI(const char* str){ //changes number stored in a string to integer
   int res = 0;
   char *ptr = (char*)str;

   while (*ptr != '\0') {
      if (isDigit(*ptr)) {
         // Integer part
         res *= 10; // Shift the previous digits to the left
         res += *ptr - 48; // Add the new one

      }
      ptr++;
   }
   return res;
}

void ItoA(int dec, char*str){
   int i = 0;
   if(dec == 0){str[i++] = 48;}
   else{
   while(dec){
         str[i++] = (dec%10) + 48;
         dec /= 10;
      }
   *(str+i) = '\0';
   reverse(str);
   }
}

void memreset(char* string, int u_size){
   
   for(int i = 0; i < u_size; i++){
      *(string+i) = '\0';
   }
}