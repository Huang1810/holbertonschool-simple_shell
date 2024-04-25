#ifndef MAIN_H
#define MATH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
char **line_div(char *command,char **arr);
char *_getline(void);
int execute(char *command);
extern char **environ;
int main(void);
#endif
