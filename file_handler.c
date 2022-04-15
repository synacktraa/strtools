#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int get_filesize(const char *file){

    FILE* fp = fopen(file, "r");
    if (fp == NULL) {
        return -1;
    }
    fseek(fp, 0L, SEEK_END);
    int res = ftell(fp);
    fclose(fp);
  
    return res;
}


int checkIfFileExists(const char * file) {

    FILE *fp;
    if((fp = fopen(file, "r")) != NULL) {
        fclose(fp);
        return 1;
    }
    return 0;
}


char* get_file_data(const char*file) {

/*
    Checks if file exists on the system, if yes
    stores the file size in buffer_len var
    by evaulating get_filesize function which 
    retrieves the file size and then reads the
    file line by line and stores it in buffer 
    and then concatenate it to data_storage
    and finally frees the buffer and return data_storage
*/
    if(!checkIfFileExists(file)) {
        fprintf(stderr, "FileError: can't open %s file.\n", file);
        exit(1);
    }

    int buffer_len = get_filesize(file)+2;
    
    FILE * file_in = fopen(file, "r");
    char* data_storage = (char*)malloc(sizeof(char) * buffer_len);
    char* buffer = (char*)malloc(sizeof(char) * buffer_len);
    
    if(data_storage == NULL || buffer == NULL)
        exit(1);

    memset(data_storage, 0, Strlen(data_storage));
    while (fgets(buffer, buffer_len, file_in))
        strcat(data_storage, buffer);

    freeIt(buffer);
    return data_storage;
}