#ifndef FILE_HANDLER_H /* Include guard */
#define FILE_HANDLER_H

int get_filesize(const char *file);
int checkIfFileExists(const char * file);
char* get_file_data(const char* file);

#endif