#include<stdio.h>
#include <string.h>
#include"convert.h"
#include"toString_utils.h"

#define BUFFER 20

int octal_to_string_arg(char *, int, int, char*);
int decimal_to_string_arg(char *, int, int, char*);
int binary_to_string_arg(char *, int, int, char*);
int hexadecimal_to_string_arg(char *, int, int, char*);


int octal_to_string_arg(char *octdump, int print_stat, int outfile_stat, char* file_out){

    char *token;
    char ch;
    FILE*out = fopen(file_out, "w");

    if(out == NULL){
        fprintf(stderr, "Error: file not found.");
        return -1;
    }            
    token = strtok(octdump, " ");
    
    while( token != NULL ) {

        ch = octToDec(AtoI(token));
        if(print_stat == 1 && outfile_stat == 0){
            printf("%c", ch);
        } else {
            fputc(ch, out);
        }
        token = strtok(NULL, " ");
    }
    fclose(out);
    remove("null.txt");

}


int decimal_to_string_arg(char *intdump, int print_stat, int outfile_stat, char* file_out){

    char *token;
    char ch;
    FILE*out = fopen(file_out, "w");

    if(out == NULL){
        fprintf(stderr, "Error: file not found.");
        return -1;
    }        
    token = strtok(intdump, " ");
    
    while( token != NULL ) {

        ch  = AtoI(token);
        if(print_stat == 1 && outfile_stat == 0){
            printf("%c", ch);
        } else {
            fputc(ch, out);
        }
        token = strtok(NULL, " ");
    }
    fclose(out);
    remove("null.txt");
}


int binary_to_string_arg(char *bindump, int print_stat, int outfile_stat, char* file_out){

    char *token;
    char ch;
    FILE*out = fopen(file_out, "w");

    if(out == NULL){
        fprintf(stderr, "Error: file not found.");
        return -1;
    }        
    
    token = strtok(bindump, " ");
    
    while( token != NULL ) {
        ch = binToDec(token);
        if(print_stat == 1 && outfile_stat == 0){
            printf("%c", ch);
        } else {
            fputc(ch, out);
        }
        token = strtok(NULL, " ");
    }

    fclose(out);
    remove("null.txt");
}


int hexadecimal_to_string_arg(char *hexdump, int print_stat, int outfile_stat, char* file_out){

    char *token;
    char ch;
    FILE*out = fopen(file_out, "w");
    if(out == NULL){
        fprintf(stderr, "Error: file not found.");
        return -1;
    }    
    token = strtok(hexdump, " ");
    
    while( token != NULL ) {
        ch = hexToDec(token);
        if(print_stat == 1 && outfile_stat == 0){
            printf("%c", ch);
        } else {
            fputc(ch, out);
        }
        token = strtok(NULL, " ");
    }
    fclose(out);
    remove("null.txt");

}


int to_string_infile(char* file_in, int print_stat, int outfile_stat, char* file_out, char* type){

    char ch;
    FILE*in = fopen(file_in, "r");
    FILE*tmp = fopen("temp", "w");

    if(in == NULL || tmp == NULL){
        fprintf(stderr, "Error: file not found.");
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
        if(!Strcmp(type, "-od")){
            ch = octToDec(AtoI(buff));
            if(print_stat == 1 && outfile_stat == 0){
                printf("%c", ch);
            } else {
                fputc(ch, out);
            }
        } else if(!Strcmp(type, "-hd")){
            ch = hexToDec(buff);
            if(print_stat == 1 && outfile_stat == 0){
                printf("%c", ch);
            } else {
                fputc(ch, out);
            }
        } else if(!Strcmp(type, "-bd")){
            ch = binToDec(buff);
            if(print_stat == 1 && outfile_stat == 0){
                printf("%c", ch);
            } else {
                fputc(ch, out);
            }
        } else if(!Strcmp(type, "-id")){
            ch = AtoI(buff);
            if(print_stat == 1 && outfile_stat == 0){
                printf("%c", ch);
            } else {
                fputc(ch, out);
            }
        } 
    }

    fclose(fp);
    fclose(out);
    remove("temp");

}


int main(int argc, char**argv){

    char opt_hd[4] = "-hd", opt_bd[4] = "-bd", opt_od[4] = "-od", opt_id[4] = "-id", 
        opt_f[3] = "-f", opt_o[3] = "-o", opt_i[3] = "-i", opt_p[3] = "-p";
    char in_file[50], out_file[50], type[5]; 
    char* arg_in;
    int i = 0, print = 0, opt_f_stat = 0, opt_o_stat = 0, opt_i_stat = 0, type_stat = 0;

    if(argc > 7){
        fprintf(stderr, "ArgumentError: invalid number of arguments.");

    } else if(argc <= 7){

        for(i; i < argc; i++){
            if(!Strcmp(argv[i], opt_f)){

                opt_f_stat = 1;
                if(argv[i+1] == NULL || 
                    !Strcmp(argv[i+1], opt_hd) ||
                    !Strcmp(argv[i+1], opt_bd) || 
                    !Strcmp(argv[i+1], opt_od) || 
                    !Strcmp(argv[i+1], opt_id) || 
                    !Strcmp(argv[i+1], opt_o) ||
                    !Strcmp(argv[i+1], opt_i) ||
                    !Strcmp(argv[i+1], opt_p)){
                        fprintf(stderr, "InputError: file not detected.\n");
                        return -1;
                }
                Strcpy(in_file, argv[i+1]);
                break;
            } else{
                continue;
            }
        }


        for(i = 0; i < argc; i++){
            if(!Strcmp(argv[i], opt_i)){

                if(argv[i+1] == NULL || 
                    !Strcmp(argv[i+1], opt_hd) ||
                    !Strcmp(argv[i+1], opt_bd) || 
                    !Strcmp(argv[i+1], opt_od) || 
                    !Strcmp(argv[i+1], opt_id) || 
                    !Strcmp(argv[i+1], opt_o) ||
                    !Strcmp(argv[i+1], opt_f) ||
                    !Strcmp(argv[i+1], opt_p)){
                        fprintf(stderr, "InputError: no input detected.\n");
                        return -1;
                }
                arg_in = argv[i+1];
                opt_i_stat = 1;

                if(opt_f_stat && opt_i_stat){
                    fprintf(stderr, "help!\n");
                    return -1;
                }

            } else{
                continue;
            }
        }
            

        for(i = 0; i < argc; i++){
            if(!Strcmp(argv[i], opt_o)){

                opt_o_stat = 1;
                if(argv[i+1] == NULL || 
                    !Strcmp(argv[i+1], opt_hd) ||
                    !Strcmp(argv[i+1], opt_bd) || 
                    !Strcmp(argv[i+1], opt_od) || 
                    !Strcmp(argv[i+1], opt_id) || 
                    !Strcmp(argv[i+1], opt_f) ||
                    !Strcmp(argv[i+1], opt_i) ||
                    !Strcmp(argv[i+1], opt_p)){
                        Strcpy(out_file, "toString_out");
                        break;
                } else {
                    Strcpy(out_file, argv[i+1]);
                    break;
                }

            } else{
                continue;
            }
        }
        for(i = 0; i < argc; i++){
            if(!Strcmp(argv[i], opt_p)){
                print = 1;
                Strcpy(out_file, "null.txt");
            } else 
                continue;
            break;
        }

        if(print == 0 && opt_o_stat == 0){
            fprintf(stderr, "OutputError: can't detect outfile.\n");
            return -1;
        }
        if(print == 1 && opt_o_stat == 1){
            fprintf(stderr, "Error: unexpected error occured.\n");
            return -1;
        }
        
        for(i = 0; i < argc; i++){
            if(!Strcmp(argv[i], opt_hd)){
                Strcpy(type, opt_hd);
                type_stat++;
            }
        }
        for(i = 0; i < argc; i++){
            if(!Strcmp(argv[i], opt_bd)){
                Strcpy(type, opt_bd);
                type_stat++;
            }
        }
        for(i = 0; i < argc; i++){
            if(!Strcmp(argv[i], opt_od)){
                Strcpy(type, opt_od);
                type_stat++;
            }
        }
        for(i = 0; i < argc; i++){
            if(!Strcmp(argv[i], opt_id)){
                Strcpy(type, opt_id);
                type_stat++;
            }
        }

        if(type_stat > 1){
            fprintf(stderr, "TypeError: input can't be more than one type.\n");
            return -1;
        } else if(type_stat == 0){
            fprintf(stderr, "TypeError: input type not specified!\n");
            return -1;
        }
        
    }


        if(opt_f_stat == 0 && opt_i_stat == 0){
            fprintf(stderr, "InputError: no data or file detected.\n");
            return -1;
        } else if(opt_f_stat == 1 && opt_i_stat == 0){
            to_string_infile(in_file, print, opt_o_stat, out_file, type);
        } else {
            if(!Strcmp(type, opt_od))
                octal_to_string_arg(arg_in, print, opt_o_stat, out_file);
            else if(!Strcmp(type, opt_hd))
                hexadecimal_to_string_arg(arg_in, print, opt_o_stat, out_file);
            else if(!Strcmp(type, opt_bd))
                binary_to_string_arg(arg_in, print, opt_o_stat, out_file);
            else if(!Strcmp(type, opt_id))
                decimal_to_string_arg(arg_in, print, opt_o_stat, out_file);
            else    
                return -1;
        }

    return 0;
}
