#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "utils.h"
#include "file_handler.h"
#include "validator.h"

char slash = '/', end = 0;

char *basename(char const *path){

    char *s = strrchr(path, slash);
    if(!s) 
        return strdup(path);
    else 
        return strdup(s + 1);

}

int octal_to_string(char *octdump, char* file_out){

    char *token;
    FILE*out;

    if(file_out != NULL){
        out = fopen(file_out, "w");

        if(out == NULL){
            fprintf(stderr, "FileError: file can't be opened.");
            return -1;
        }            
    }
    

    token = strtok(octdump, " ");
    
    while( token != NULL ) {
        
        if(validateOctalValue(token) == -1) {
            fprintf(stderr, "ValueError: detected incorrect octal value.");
            putchar(end);
            return 1;

        }
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


int decimal_to_string(char *intdump, char* file_out){

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


int binary_to_string(char *bindump, char* file_out){

    char *token;
    FILE*out;

    if(file_out != NULL){
        out = fopen(file_out, "w");

        if(out == NULL){
            fprintf(stderr, "FileError: file can't be opened.");
            return -1;
        }            
    }


    
    token = strtok(bindump, " ");
    
    while( token != NULL ) {
        if(validateBinValue(token) == -1) {
            fprintf(stderr, "ValueError: detected incorrect binary value.");
            putchar(end);
            return 1;

        } else if(validateBinValue(token) == -2) {
            fprintf(stderr, "ValueError: binary value's greater than expected.");
            putchar(end);
            return 1;
        }
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


int hexadecimal_to_string(char *hexdump, char* file_out){

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


int stringToDecimal(char* string, char* file_out){

    FILE*out;

    if(file_out != NULL){
        out = fopen(file_out, "w");

        if(out == NULL){
            fprintf(stderr, "FileError: file can't be opened.");
            return -1;
        }            
    }

    for(size_t i = 0; i < strlen(string); ++i){
        int ch = *(string+i);

        if(file_out != NULL) {fprintf(out, "%d", ch); fputc(' ', out);}
        else printf("%d ", ch);
    }    
    if(file_out == NULL)
        putchar(end);
    else
        fclose(out);

    return 0;
}

int stringToOctal(char* string, char* file_out){

    int ch;
    FILE*out;

    if(file_out != NULL){
        out = fopen(file_out, "w");

        if(out == NULL){
            fprintf(stderr, "FileError: file can't be opened.");
            return -1;
        }            
    }

    for(size_t i = 0; i < strlen(string); ++i){
        ch = decToOct(*(string+i));

        if(file_out != NULL) {fprintf(out, "%d", ch); fputc(' ', out);}
        else printf("%d ", ch);
    }    
    if(file_out == NULL)
        putchar(end);
    else
        fclose(out);

    return 0;
}

int stringToHexadecimal(char* string, char* file_out){

    char str[5];
    FILE*out;

    if(file_out != NULL){
        out = fopen(file_out, "w");

        if(out == NULL){
            fprintf(stderr, "FileError: file can't be opened.");
            return -1;
        }            
    }

    for(size_t i = 0; i < strlen(string); ++i){
        strcpy(str, decToHex(*(string+i)));

        if(file_out != NULL) {fputs(str, out); fputc(' ', out);}
        else printf("%s ", str);
    }    
    if(file_out == NULL)
        putchar(end);
    else
        fclose(out);

    return 0;
}

int stringToBinary(char* string, char* file_out){

    char str[10];
    FILE*out;

    if(file_out != NULL){
        out = fopen(file_out, "w");

        if(out == NULL){
            fprintf(stderr, "FileError: file can't be opened.");
            return -1;
        }            
    }
    for(size_t i = 0; i < strlen(string); ++i){
        strcpy(str, decToBin(*(string+i)));

        if(file_out != NULL) {fputs(str, out); fputc(' ', out);}
        else printf("%s ", str);
    }    
    if(file_out == NULL)
        putchar(end);
    else
        fclose(out);

    return 0;
}


void usage(char* param){
    fprintf(stderr, "\nUsage: %s <type|conversion> <input> [ data | file ] -o outfile.txt\n", param);
}

void help(){
    fprintf(stdout, "\n|CLI options|:-\
    \n   type/conversion:\
    \n      -O  converts octal dump to string.\
    \n      -B  converts binary dump to string.\
    \n      -D  converts decimal dump to string.\
    \n      -X  converts hexadecimal dump to string.\
    \n    [if -s flag is specified, it converts string to base<int>.]\
    \n\n   input:\n      -i  takes next argument as data string.\
    \n      -f  takes next argument as filename.\
    \n\n   optional:\n      -o  takes next argument as filename.\
    \n\t   (if filename is null, it's set to strtools_out as filename.)\
    \n\t   [if '-o' is not used, result is printed to STDOUT.]\n\n");
}


int arg_validate(char* arg){
    if(arg == NULL || 
        !strcmp(arg, "-X") ||
        !strcmp(arg, "-B") || 
        !strcmp(arg, "-O") || 
        !strcmp(arg, "-D") || 
        !strcmp(arg, "-f") ||
        !strcmp(arg, "-i") ||
        !strcmp(arg, "-o") ||
        !strcmp(arg, "-s")){
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

    char *opt_hd = "-X", *opt_bd = "-B", *opt_od = "-O", *opt_id = "-D", 
         *opt_f = "-f", *opt_o = "-o", *opt_i = "-i", *opt_tostr = "-s";
    char *out_file = NULL, type[5]; 
    char *storage, *exe = basename(argv[0]);
    int i = 0, opt_f_stat = 0, opt_i_stat = 0, type_stat = 0, opt_tostr_stat = 0;

    if(argc == 2 && !strcmp(argv[1], "-h")){
        usage(exe);
        help();
        freeIt(exe);
        return -1;


    } else if(argc <= 7){

        for(;i < argc; i++){
            if(!strcmp(argv[i], opt_f)){

                opt_f_stat = 1;
                if(arg_validate(argv[i+1]) == -1){
                    fprintf(stderr, "\nInputError: file not detected.\n");
                    usage(exe);
                    fprintf(stderr, "\nFor more, check help section:\
                    \n    %s -h\n\n", exe);
                    freeIt(exe);
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
                    usage(exe);
                    fprintf(stderr, "\nFor more, check help section:\
                    \n    %s -h\n\n", exe);
                    freeIt(exe);
                    return -1;

                }
                storage = argv[i+1];

                if(opt_f_stat && opt_i_stat){
                    usage(exe);
                    help();
                    freeIt(exe);
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

        for(i = 0; i < argc; i++){
            if(!strcmp(argv[i], opt_tostr)){
                opt_tostr_stat = 1;
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
        usage(exe);
        fprintf(stderr, "\nFor more, check help section:\
        \n    %s -h\n\n", exe);
        freeIt(exe);
        return -1;

    }


    if(opt_f_stat == 0 && opt_i_stat == 0){
        fprintf(stderr, "\nInputError: no data or file detected.\n");
        help();
        return -1;
    } else if(opt_tostr_stat) {

        if(!strcmp(type, opt_od))
            stringToOctal(storage, out_file);
        else if(!strcmp(type, opt_hd))
            stringToHexadecimal(storage, out_file);
        else if(!strcmp(type, opt_bd))
            stringToBinary(storage, out_file);
        else if(!strcmp(type, opt_id))
            stringToDecimal(storage, out_file);
    } else {
        if(!strcmp(type, opt_od))
            octal_to_string(storage, out_file);
        else if(!strcmp(type, opt_hd))
            hexadecimal_to_string(storage, out_file);
        else if(!strcmp(type, opt_bd))
            binary_to_string(storage, out_file);
        else if(!strcmp(type, opt_id))
            decimal_to_string(storage, out_file);
        else    
            return -1;
        
    }
    if(opt_f_stat)
        freeIt(storage);
    
    return 0;
}
