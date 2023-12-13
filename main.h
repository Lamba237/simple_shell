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


void display_prompt(void);
void handle_eof(void);
void execute_command(char *command);


#endif /* MAIN_H */
