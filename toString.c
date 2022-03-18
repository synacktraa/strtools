#include <stdio.h>
#include <string.h>
#include "toString_utils.h"

#define BUFFER 20

char *win_bname_parser(char const *);
char *unix_bname_parser(char const *);
int octal_to_string_arg(char *, int, char*);
int decimal_to_string_arg(char *, int, char*);
int binary_to_string_arg(char *, int, char*);
int hexadecimal_to_string_arg(char *, int, char*);
int to_string_infile(char*, int, char*, char*);

char *win_bname_parser(char const *path) {
        char *s = strrchr(path, '\\');
        if(!s) 
            return strdup(path);
         else 
            return strdup(s + 1);
}

char *unix_bname_parser(char const *path) {
        char *s = strrchr(path, '/');
        if(!s) 
            return strdup(path);
         else 
            return strdup(s + 1);
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

        ch = octToDec(AtoI(token));
        if(outfile_stat == 1){
            fputc(ch, out);
        } else {
            printf("%c", ch);
        }
        token = strtok(NULL, " ");
    }

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

        ch  = AtoI(token);
        if(outfile_stat == 1){
            fputc(ch, out);
        } else {
            printf("%c", ch);
        }
        token = strtok(NULL, " ");
    }
    
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
        ch = binToDec(token);
        if(outfile_stat == 1){
            fputc(ch, out);
        } else {
            printf("%c", ch);
        }
        token = strtok(NULL, " ");
    }

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
        ch = hexToDec(token);
        if(outfile_stat == 1){
            fputc(ch, out);
        } else {
            printf("%c", ch);
        }
        token = strtok(NULL, " ");
    }
    
    fclose(out);
    remove("nil");

    return 0;
}


int to_string_infile(char* file_in, int outfile_stat, char* file_out, char* type){

    char ch;
    FILE*in = fopen(file_in, "r");
    FILE*tmp = fopen("temp", "w");

    if(in == NULL || tmp == NULL){
        fprintf(stderr, "FileError: file can't be opened.");
        return -1;
    }

    while((ch = fgetc(in)) != EOF){
        if(ch == ' ')
            ch = '\n';
        fputc(ch, tmp);
    }

    fclose(in);
    fclose(tmp);

    ch = 0;
    FILE*fp = fopen("temp", "r");
    FILE*out = fopen(file_out, "w");

    char buff[BUFFER];
    while (fgets(buff, BUFFER, fp)){

        buff[strcspn(buff, "\n")] = 0;
        if(!strcmp(type, "-od")){

            ch = octToDec(AtoI(buff));
            if(outfile_stat == 1){
                fputc(ch, out);
            } else {
                printf("%c", ch);
            }

        } else if(!strcmp(type, "-hd")){

            ch = hexToDec(buff);
            if(outfile_stat == 1){
                fputc(ch, out);
            } else {
                printf("%c", ch);
            }

        } else if(!strcmp(type, "-bd")){

            ch = binToDec(buff);
            if(outfile_stat == 1){
                fputc(ch, out);
            } else {
                printf("%c", ch);
            }

        } else if(!strcmp(type, "-id")){

            ch = AtoI(buff);
            if(outfile_stat == 1){
                fputc(ch, out);
            } else {
                printf("%c", ch);
            }

        } 
    }

    fclose(fp); fclose(out);
    remove("temp");
    remove("nil");

    return 0;
}


int main(int argc, char**argv){

    auto void usage(char*);
    auto void help( );

    char opt_hd[4] = "-hd", opt_bd[4] = "-bd", opt_od[4] = "-od", opt_id[4] = "-id", 
        opt_f[3] = "-f", opt_o[3] = "-o", opt_i[3] = "-i";
    char in_file[50], out_file[50], type[5]; 
    char* arg_in;
    int i = 0, opt_f_stat = 0, opt_o_stat = 0, opt_i_stat = 0, type_stat = 0;

    
    void usage(char* param){
        fprintf(stderr, "\nUsage: %s <type> <input> data|file -o outfile.txt\n", param);
    }

    void help(){
        fprintf(stderr, "\n|CLI options|:-\
        \n   type:\n      -od = The data passed should be octal.\
        \n      -bd = The data passed should be binary.\
        \n      -id = The data passed should be decimal.\
        \n      -hd = The data passed should be hexadecimal.\
        \n\n   input:\n      -i = takes next argument as data string.\
        \n      -f = takes next argument as filename.\
        \n\n   optional:\n      -o = takes next argument as filename.\
        \n\t   (if filename is null, it's set to toString_out as filename.)\
        \n\t   [if '-o' is not used, result is printed to STDOUT.]\n\n");
    }
    char* binfile = unix_bname_parser(argv[0]);
    
    if(!strcmp(argv[0], binfile)){
        memset(binfile, '\0', strlen(binfile));
        strcpy(binfile, win_bname_parser(argv[0]));
    }

    if(argc == 1){
        usage(binfile);
        fprintf(stderr, "\nFor more, check help section:\
        \n    %s -h\n\n", binfile);
        return -1;

    } else if(argc == 2 && !strcmp(argv[1], "-h")){
        usage(binfile);
        help();
        return 1;

    } else if(argc > 6){
        fprintf(stderr, "\nArgumentError: invalid number of arguments.");
        return -1;

    } else if(argc <= 6){

        for(;i < argc; i++){
            if(!strcmp(argv[i], opt_f)){

                opt_f_stat = 1;
                if(argv[i+1] == NULL || 
                    !strcmp(argv[i+1], opt_hd) ||
                    !strcmp(argv[i+1], opt_bd) || 
                    !strcmp(argv[i+1], opt_od) || 
                    !strcmp(argv[i+1], opt_id) || 
                    !strcmp(argv[i+1], opt_o) ||
                    !strcmp(argv[i+1], opt_i)){
                        fprintf(stderr, "\nInputError: file not detected.\n");
                        usage(binfile);
                        fprintf(stderr, "\nFor more, check help section:\
                        \n    %s -h\n\n", binfile);
                        return -1;
                }
                strcpy(in_file, argv[i+1]);
                break;
            } else{
                continue;
            }
        }


        for(i = 0; i < argc; i++){
            if(!strcmp(argv[i], opt_i)){

                if(argv[i+1] == NULL || 
                    !strcmp(argv[i+1], opt_hd) ||
                    !strcmp(argv[i+1], opt_bd) || 
                    !strcmp(argv[i+1], opt_od) || 
                    !strcmp(argv[i+1], opt_id) || 
                    !strcmp(argv[i+1], opt_o) ||
                    !strcmp(argv[i+1], opt_f)){
                        fprintf(stderr, "\nInputError: no input detected.\n");
                        usage(binfile);
                        fprintf(stderr, "\nFor more, check help section:\
                        \n    %s -h\n\n", binfile);
                        return -1;
                }
                arg_in = argv[i+1];
                opt_i_stat = 1;

                if(opt_f_stat && opt_i_stat){
                    usage(binfile);
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
                if(argv[i+1] == NULL || 
                    !strcmp(argv[i+1], opt_hd) ||
                    !strcmp(argv[i+1], opt_bd) || 
                    !strcmp(argv[i+1], opt_od) || 
                    !strcmp(argv[i+1], opt_id) || 
                    !strcmp(argv[i+1], opt_f) ||
                    !strcmp(argv[i+1], opt_i)){
                        strcpy(out_file, "toString_out");
                        break;
                } else {
                    strcpy(out_file, argv[i+1]);
                    break;
                }

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

        if(opt_o_stat == 0)
            strcpy(out_file, "nil");

        if(opt_f_stat == 0 && opt_i_stat == 0){
            fprintf(stderr, "\nInputError: no data or file detected.\n");
            help();
            return -1;
        } else if(opt_f_stat == 1 && opt_i_stat == 0){
            to_string_infile(in_file, opt_o_stat, out_file, type);
        } else {
            if(!strcmp(type, opt_od))
                octal_to_string_arg(arg_in, opt_o_stat, out_file);
            else if(!strcmp(type, opt_hd))
                hexadecimal_to_string_arg(arg_in, opt_o_stat, out_file);
            else if(!strcmp(type, opt_bd))
                binary_to_string_arg(arg_in, opt_o_stat, out_file);
            else if(!strcmp(type, opt_id))
                decimal_to_string_arg(arg_in, opt_o_stat, out_file);
            else    
                return -1;
        }

    return 0;
}
