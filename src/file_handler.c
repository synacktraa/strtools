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


char* get_file_data(const char*file, int status) {


    if(!checkIfFileExists(file)) {
        fprintf(stderr, "FileError: can't open %s file.\n", file);
        exit(1);
    }

    int buffsize = 256;
    FILE * fptr = fopen(file, "rb");
    char* buffer = (char*)malloc(buffsize);
    
    if(buffer == NULL) exit(EXIT_FAILURE);

    int ch, cursor = 0;

    while((ch = fgetc(fptr)) != EOF) { 
        
        // if ch is not the end of file, buffer is appended with ch char value
        if(isprint(ch))
            buffer[cursor++] = (char)ch;
	else if( ch == '\t' || ch == '\n'){
            if(status)
		buffer[cursor++] = (char)ch;
	    else
	        buffer[cursor++] = ' ';
	}
        /* if cursor crosses current buffer size
            it's doubled in size and new size gets reallocated */
        if(cursor >= buffsize - 1) { 
            buffsize <<=1;
            buffer = (char*)realloc(buffer, buffsize);
        	if(buffer == NULL) exit(EXIT_FAILURE);
        }
        
    } // while ch is not end of the file
    
    fclose(fptr); //always close the file pointer BAKA ^_^         

    return buffer;
}
