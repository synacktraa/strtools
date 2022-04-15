#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "utils.h"
#include "file_handler.h"
#include "validator.h"

#define BUFFER 20

char *basename(char const *path);
int octalToStr(char *, char*);
int decimalToStr(char *, char*);
int binaryToStr(char *, char*);
int hexadecimalToStr(char *, char*);

char slash = '/', end = 0;


char *basename(char const *path){

    char *s = strrchr(path, slash);
    if(!s) 
        return strdup(path);
    else 
        return strdup(s + 1);

}

int octalToStr(char *octdump, char* file_out){

    char *token;
    FILE*out;

    if(file_out != NULL){
        out = fopen(file_out, "w");

        if(out == NULL){
            fprintf(stderr, "FileError: file can't be opened.");
            return -1;
        }            
    }
    
    if(validateOctalValue(octdump) == -1) {
        fprintf(stderr, "ValueError: detected incorrect octal value.");
        putchar(end);
        return 1;

    }
    token = strtok(octdump, " ");
    
    while( token != NULL ) {
        

        char ch = octToDec(AtoI(token));

        if(file_out != NULL) fputc(ch, out);
        else putchar(ch);

        token = strtok(NULL, " ");
    }
    if(file_out == NULL)
        putchar(end);
    else
        fclose(out);

    return 0;
    }


int decimalToStr(char *intdump, char* file_out){

    char *token;
    FILE*out;

    if(file_out != NULL){
        out = fopen(file_out, "w");

        if(out == NULL){
            fprintf(stderr, "FileError: file can't be opened.");
            return -1;
        }            
    }       
    
    if(validateIntValue(intdump) == -1) {
        fprintf(stderr, "ValueError: incorrect value detected.");
        putchar(end);
        return 1;
    }  
    
    token = strtok(intdump, " ");
    
    while( token != NULL ) {  

        char ch  = AtoI(token);

        if(file_out != NULL) fputc(ch, out);
        else putchar(ch);

        token = strtok(NULL, " ");
    }
    if(file_out == NULL)
        putchar(end);
    else
        fclose(out);


    return 0;
}


int binaryToStr(char *bindump, char* file_out){

    char *token;
    FILE*out;

    if(file_out != NULL){
        out = fopen(file_out, "w");

        if(out == NULL){
            fprintf(stderr, "FileError: file can't be opened.");
            return -1;
        }            
    }

    if(validateBinValue(bindump) == -1) {
        fprintf(stderr, "ValueError: detected incorrect binary value.");
        putchar(end);
        return 1;

    } else if(validateBinValue(bindump) == -2) {
        fprintf(stderr, "ValueError: binary value's greater than expected.");
        putchar(end);
        return 1;
    }
    
    token = strtok(bindump, " ");
    
    while( token != NULL ) {

        char ch = binToDec(token);

        if(file_out != NULL) fputc(ch, out);
        else putchar(ch);

        token = strtok(NULL, " ");
    }
    if(file_out == NULL)
        putchar(end);
    else
        fclose(out);


    return 0;
}


int hexadecimalToStr(char *hexdump, char* file_out){

    char *token;
    FILE*out;

    if(file_out != NULL){
        out = fopen(file_out, "w");

        if(out == NULL){
            fprintf(stderr, "FileError: file can't be opened.");
            return -1;
        }            
    }  

    if(validateHexValue(hexdump) == -1) {
        fprintf(stderr, "ValueError: detected incorrect hex value.");
        putchar(end);
        exit(1);   

    }

    token = strtok(hexdump, " ");
    while( token != NULL ) {

        char ch = hexToDec(token);

        if(file_out != NULL) fputc(ch, out);
        else putchar(ch);

        token = strtok(NULL, " ");
    }
    if(file_out == NULL)
        putchar(end);
    else
        fclose(out);


    return 0;
}


void usage(char* param){
    fprintf(stderr, "\nUsage: %s <type> <input> data|file -o outfile.txt\n", param);
}

void help(){
    fprintf(stderr, "\n|CLI options|:-\
    \n   type:\n      -od = processes data as octal.\
    \n      -bd = processes data as binary.\
    \n      -id = processes data as decimal.\
    \n      -hd = processes data as hexadecimal.\
    \n\n   input:\n      -i = takes next argument as data string.\
    \n      -f = takes next argument as filename.\
    \n\n   optional:\n      -o = takes next argument as filename.\
    \n\t   (if filename is null, it's set to toString_out as filename.)\
    \n\t   [if '-o' is not used, result is printed to STDOUT.]\n\n");
}


int arg_validate(char* arg){
    if(arg == NULL || 
        !strcmp(arg, "-hd") ||
        !strcmp(arg, "-bd") || 
        !strcmp(arg, "-od") || 
        !strcmp(arg, "-id") || 
        !strcmp(arg, "-f") ||
        !strcmp(arg, "-i") ||
        !strcmp(arg, "-o")){
            return -1;
        }
    return 0;
}


int main(int argc, char**argv){

    #ifdef _WIN32
        end = 0;
        slash = '\\';
    #elif __unix__
        end = 10;
        slash = '/';
    #endif

    char *opt_hd = "-hd", *opt_bd = "-bd", *opt_od = "-od", *opt_id = "-id", 
         *opt_f = "-f", *opt_o = "-o", *opt_i = "-i";
    char *out_file = NULL, type[5]; 
    char* storage;
    int i = 0, opt_f_stat = 0, opt_i_stat = 0, type_stat = 0;

    if(argc == 2 && !strcmp(argv[1], "-h")){
        usage(basename(argv[0]));
        help();
        return 1;

    } else if(argc > 6){
        fprintf(stderr, "\nArgumentError: invalid number of arguments.");
        return -1;

    } else if(argc <= 6){

        for(;i < argc; i++){
            if(!strcmp(argv[i], opt_f)){

                opt_f_stat = 1;
                if(arg_validate(argv[i+1]) == -1){
                    fprintf(stderr, "\nInputError: file not detected.\n");
                    usage(basename(argv[0]));
                    fprintf(stderr, "\nFor more, check help section:\
                    \n    %s -h\n\n", basename(argv[0]));
                    return -1;
                }
                storage = get_file_data(argv[i+1]);
                break;
            } else{
                continue;
            }
        }


        for(i = 0; i < argc; i++){
            if(!strcmp(argv[i], opt_i)){

                opt_i_stat = 1;
                if(arg_validate(argv[i+1]) == -1){
                    fprintf(stderr, "\nInputError: no input detected.\n");
                    usage(basename(argv[0]));
                    fprintf(stderr, "\nFor more, check help section:\
                    \n    %s -h\n\n", basename(argv[0]));
                    return -1;
                }
                storage = argv[i+1];

                if(opt_f_stat && opt_i_stat){
                    usage(basename(argv[0]));
                    help();
                    return -1;
                }
        
            } else{
                continue;
            }
        }

        for(i = 0; i < argc; i++){
            if(!strcmp(argv[i], opt_o)){

                if(arg_validate(argv[i+1]) == -1){
                    out_file = "strtools_out";
                } else {
                    out_file = argv[i+1];
                }
                break;
            } else{
                continue;
            }
        }
        
        for(i = 0; i < argc; i++){
            if(!strcmp(argv[i], opt_hd)){
                strcpy(type, opt_hd);
                type_stat++;
            }
        }
        for(i = 0; i < argc; i++){
            if(!strcmp(argv[i], opt_bd)){
                strcpy(type, opt_bd);
                type_stat++;
            }
        }
        for(i = 0; i < argc; i++){
            if(!strcmp(argv[i], opt_od)){
                strcpy(type, opt_od);
                type_stat++;
            }
        }
        for(i = 0; i < argc; i++){
            if(!strcmp(argv[i], opt_id)){
                strcpy(type, opt_id);
                type_stat++;
            }
        }

        if(type_stat > 1){
            fprintf(stderr, "\nTypeError: data can't be of more than one type.\n");
            help();
            return -1;
        } else if(type_stat == 0){
            fprintf(stderr, "\nTypeError: data type not specified!\n");
            help();
            return -1;
        }
        
    } else{
        usage(basename(argv[0]));
        fprintf(stderr, "\nFor more, check help section:\
        \n    %s -h\n\n", basename(argv[0]));
        return -1;

    }


    if(opt_f_stat == 0 && opt_i_stat == 0){
        fprintf(stderr, "\nInputError: no data or file detected.\n");
        help();
        return -1;
    } else {
        if(!strcmp(type, opt_od))
            octalToStr(storage, out_file);
        else if(!strcmp(type, opt_hd))
            hexadecimalToStr(storage, out_file);
        else if(!strcmp(type, opt_bd))
            binaryToStr(storage, out_file);
        else if(!strcmp(type, opt_id))
            decimalToStr(storage, out_file);
        else    
            return -1;
        
        if(opt_f_stat)
            freeIt(storage);
    }

    return 0;
}
