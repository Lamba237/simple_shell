#ifndef MAIN_H
#define MAIN_H

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int startsWithForwardSlash(const char *str);
char *get_file_loc(char *path, char *file_name);
char *get_file_path(char *file_name);
/* custom function */
char *_strcpy(char *dest, char *source);
char *_strcat(char *str, char *ptr);
char *_strdup(char *ptr);
size_t _strlen(char *ptr);

#endif /* MAIN_H */
