#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int start_with_slash(const char *ptr);
char *get_file_path(char *name_file);
char *Strcat(const char *dest, const char *source);
char *get_file(char *path, char *file_name);
char *_strcpy(char *dest, const char *source);
char **parse_Arg(char *command);
size_t custom_strlen(const char *str);
void remove_newline(char *str);
int _putchar(char c);
char *_strdup(const char *str);
void print_string(const char *str);

#endif /* MAIN_H */
