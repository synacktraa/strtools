#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "toString_utils.h"

#define BUFFER 20

char *basename(char const *);
int octal_to_string_arg(char *, int, char*);
int decimal_to_string_arg(char *, int, char*);
int binary_to_string_arg(char *, int, char*);
int hexadecimal_to_string_arg(char *, int, char*);
int to_string_infile(char*, int, char*, char*);

char slash = '/', end = 0;

char *basename(char const *path){

    char *s = strrchr(path, slash);
    if(!s) 
        return strdup(path);
    else 
        return strdup(s + 1);

}


int get_filesize(char file_name[]){

    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        return -1;
    }
    fseek(fp, 0L, SEEK_END);
    int res = ftell(fp);
    fclose(fp);
  
    return res;
}


int checkIfFileExists(const char * filename) {

    FILE *file;
    if((file = fopen(filename, "r")) != NULL) {
        fclose(file);
        return 1;
    }
    return 0;
}


char* get_file_data(char*file) {

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
        fprintf(stderr, "FileError: can't open %s file.", file);
        exit(1);
    }

    int buffer_len = get_filesize(file)+2;
    
    FILE * file_in = fopen(file, "r");
    char* data_storage = (char*)malloc(sizeof(char) * buffer_len);
    char* buffer = (char*)malloc(sizeof(char) * buffer_len);
    
    if(data_storage == NULL || buffer == NULL)
        exit(1);

    memset(data_storage, 0, strlen(data_storage));
    while (fgets(buffer, buffer_len, file_in))
        strcat(data_storage, buffer);

    free(buffer);
    return data_storage;
}

int validateOctalValue(char*octal_value) {

    int val = AtoI(octal_value);
    
    char str[4];
    ItoA(val, str);
    
    /* Octal values can't have the value 8 and 9,
       so searches for them, if present
       it returns -1 */
    if(strcspn(str, "89") != strlen(str))
        return -1;

    if(val < 0 || val > 176)
        return -2;

    return 0;
}

int validateHexValue(char*hex_value) {

    /* Hex values can't have values other than
       "123456789ABCDEF" */
    if(strspn(hex_value, "0123456789ABCDEFabcdef") != strlen(hex_value)){

        return -1;
    }
    
    if(strlen(hex_value) > 2)
        return -2;

    return 0;
}

int validateIntValue(char*int_value) {

    if(AtoI(int_value) < 0 || AtoI(int_value) > 126)
        return -1;

    return 0;
}

int validateBinValue(char*bin_value) {

    /* Binary values can't have values other 
       than 0 and 1 */
    for(int i = 0; i < strlen(bin_value); ++i){
        if(*(bin_value+i) != 48 && *(bin_value+i) != 49)
            return -1;
    }

    if(binToDec(bin_value) > 126)
        return -2;

    return 0;
}


int octal_to_string_arg(char *octdump, int outfile_stat, char* file_out){

    char *token;
    char ch;
    FILE*out = fopen(file_out, "w");

    if(out == NULL){
        fprintf(stderr, "FileError: file can't be opened.");
        return -1;
    }            
    
    token = strtok(octdump, " ");
    
    while( token != NULL ) {
        
        if(validateOctalValue(token) == -1) {
            fprintf(stderr, "\n\nValueError: detected incorrect octal value.");
            return 1;

        } else if(validateOctalValue(token) == -2) {
            fprintf(stderr, "\n\nValueError: octal value's greater than expected.");
            return 1;
        }

        ch = octToDec(AtoI(token));

        if(outfile_stat) fputc(ch, out);
        else printf("%c", ch);

        token = strtok(NULL, " ");
    }
    if(!outfile_stat)
        putchar(end);

    fclose(out);
    remove("nil");

    return 0;
    }


int decimal_to_string_arg(char *intdump, int outfile_stat, char* file_out){

    char *token;
    char ch;
    FILE*out = fopen(file_out, "w");

    if(out == NULL){
        fprintf(stderr, "FileError: file can't be opened.");
        return -1;
    }        
    
    token = strtok(intdump, " ");
    
    while( token != NULL ) {

        if(validateIntValue(token) == -1) {
            fprintf(stderr, "\n\nValueError: decimal value out of range.");
            return 1;
        }    

        ch  = AtoI(token);

        if(outfile_stat) fputc(ch, out);
        else printf("%c", ch);

        token = strtok(NULL, " ");
    }
    if(!outfile_stat)
        putchar(end);
    
    fclose(out);
    remove("nil");

    return 0;
}


int binary_to_string_arg(char *bindump, int outfile_stat, char* file_out){

    char *token;
    char ch;
    FILE*out = fopen(file_out, "w");

    if(out == NULL){
        fprintf(stderr, "FileError: file can't be opened.");
        return -1;
    }        
    
    token = strtok(bindump, " ");
    
    while( token != NULL ) {

        if(validateBinValue(token) == -1) {
            fprintf(stderr, "\n\nValueError: detected incorrect binary value.");
            return 1;

        } else if(validateBinValue(token) == -2) {
            fprintf(stderr, "\n\nValueError: binary value's greater than expected.");
            return 1;
        }

        ch = binToDec(token);

        if(outfile_stat) fputc(ch, out);
        else printf("%c", ch);

        token = strtok(NULL, " ");
    }
    if(!outfile_stat)
        putchar(end);

    fclose(out);
    remove("nil");

    return 0;
}


int hexadecimal_to_string_arg(char *hexdump, int outfile_stat, char* file_out){

    char *token;
    char ch;
    FILE*out = fopen(file_out, "w");

    if(out == NULL){
        fprintf(stderr, "FileError: file can't be opened.");
        return -1;
    }    

    token = strtok(hexdump, " ");
    
    while( token != NULL ) {
        puts(token);    
        if(validateHexValue(token) == -1) {
            fprintf(stderr, "\n\nValueError: detected incorrect hex value.");
            return 1;     

        } else if(validateHexValue(token) == -2) {
            fprintf(stderr, "\n\nValueError: hexadecimal value's greater than expected.");
            return 1;
        }

        ch = hexToDec(token);

        if(outfile_stat) fputc(ch, out);
        // else printf("%c", ch);

        token = strtok(NULL, " ");
    }
    if(!outfile_stat)
        putchar(end);

    fclose(out);
    remove("nil");

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
    char *in_file = NULL, *out_file, type[5]; 
    char* storage;
    int i = 0, opt_f_stat = 0, opt_o_stat = 0, opt_i_stat = 0, type_stat = 0;

    if(argc == 1){
        usage(basename(argv[0]));
        fprintf(stderr, "\nFor more, check help section:\
        \n    %s -h\n\n", basename(argv[0]));
        return -1;

    } else if(argc == 2 && !strcmp(argv[1], "-h")){
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
                in_file = argv[i+1];
                break;
            } else{
                continue;
            }
        }


        for(i = 0; i < argc; i++){
            if(!strcmp(argv[i], opt_i)){

                if(arg_validate(argv[i+1]) == -1){
                    fprintf(stderr, "\nInputError: no input detected.\n");
                    usage(basename(argv[0]));
                    fprintf(stderr, "\nFor more, check help section:\
                    \n    %s -h\n\n", basename(argv[0]));
                    return -1;
                }
                storage = argv[i+1];
                opt_i_stat = 1;

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

                opt_o_stat = 1;
                if(arg_validate(argv[i+1]) == -1){
                    out_file = "toString_out";
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
        
    }

    if(in_file != NULL){

        storage = get_file_data(in_file);
    }

    if(opt_o_stat == 0)
        out_file = "nil";

    if(opt_f_stat == 0 && opt_i_stat == 0){
        fprintf(stderr, "\nInputError: no data or file detected.\n");
        help();
        return -1;
    } else {
        if(!strcmp(type, opt_od))
            octal_to_string_arg(storage, opt_o_stat, out_file);
        else if(!strcmp(type, opt_hd))
            hexadecimal_to_string_arg(storage, opt_o_stat, out_file);
        else if(!strcmp(type, opt_bd))
            binary_to_string_arg(storage, opt_o_stat, out_file);
        else if(!strcmp(type, opt_id))
            decimal_to_string_arg(storage, opt_o_stat, out_file);
        else    
            return -1;
    }

    return 0;
}
