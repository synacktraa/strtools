#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include "utils.h"


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

    int buffsize = 1024;
    FILE * fptr = fopen(file, "rb");
    char* buffer = (char*)malloc(buffsize);
    
    if(buffer == NULL) exit(EXIT_FAILURE);

    int ch, cursor = 0;
    do { 
        do { 
            ch = fgetc(fptr); //storing char in ch
            
            // if ch is not the end of file, buffer is appended with ch char value
            if(ch != EOF){
                if(isprint(ch) || ch == '\t')
                    buffer[cursor++] = (char)ch;
            } 

            /* if cursor crosses current buffer size
                it's doubled in size and new size gets reallocated */
            if(cursor >= buffsize - 1) { 
                buffsize <<=1;
                buffer = (char*)realloc(buffer, buffsize);
            }
        } while(ch != EOF && ch != '\n'); // will continue until ch is not EOF and newline character
        
        buffer[cursor++] ='\n';
    } while(ch != EOF); // while ch is not end of the file
    
    buffer[--cursor] = '\0';
    fclose(fptr); //always close the file pointer BAKA ^_^         

    return buffer;
}