#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

char **arguments(const char *command);
size_t custom_strlen(const char *str);
void remove_newline(char *str);
int _putchar(char c);
char *_strdup(const char *str);
void print_string(const char *str);
void execute_command(char *command);

#endif /* MAIN_H */
