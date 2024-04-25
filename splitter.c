#include "main.h"
/**
* line_div - splits given string into parts
*
* @command: The command string to parse.
* @arr: An array of strings to store the parsed arguments.
*
* Return: modified char array.
*/
char **line_div(char *command,char **arr)
{
char *token;
int i = 0;
token = strtok(command, " \n\t");
while (token != NULL && i < 63)
{
arr[i++] = token;
token = strtok(NULL, " \n\t");
}
arr[i++] = NULL;
return (arr);
}
