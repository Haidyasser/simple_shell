#ifndef SHELL_H
#define SHELL_H
#define delim " \n\"\'*;"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void display(char *);
char *read_command(int *);
char **split_command(char *, int *);
int excute(char **);
char *get_location(char *command);

#endif
