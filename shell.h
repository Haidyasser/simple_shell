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

/*main functions*/
void display(char *);
char *read_command(int *);
char **split_command(char *, int *);
int excute(char **);
char *get_location(char *command);

/*shell functions*/
int shell_exit(char **);
int shell_env(char **);
int shell_cd(char **);

/*string functions*/
int _strcmp(char *, char *);
char *_strcpy(char *, char *);
int _strlen(char *);

#endif
