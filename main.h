#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>

extern char **environ;

void prompt(void);
char *_getline(void);
int exec(char **token, char **argv, int path);
char **_strtok(char *line);
int main(int argc, char **argv);
int builtin(char **token);
int print_env(char **token);
int eof(char **token);
int exit_function(char **token);
int _strlen(char *line);

#endif