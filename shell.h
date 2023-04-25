#ifndef SHELL_H
#define SHELL_H
#define delim " \n\"\';"
#define environ __environ

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include  <signal.h>

/*main functions*/
void display(char *);
char *read_command(int *);
char **split_command(char *, int *);
int excute(char **);
char *get_location(char *command);
int _getline(char **line);

/*shell functions*/
int shell_exit(char **);
int shell_env(char **);
int shell_cd(char **);
void handlec(int sig);

/*string functions*/
int _strcmp(char *, char *);
char *_strcpy(char *, char *);
char *_strncpy(char *, char *, int);
int _strlen(char *);
char *_strdup(char *);
char *_strcat(char *, char *);

#endif
