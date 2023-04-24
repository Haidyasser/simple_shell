#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void display(char *);
char *read_command();
char **split_command(char *);
int excute(char **);
char *get_location(char *command);

#endif
