#include "main.h"
/**
* _strtok - function that split line to arguments
* @line: array of char
* Return: the pointer args
*/

char **_strtok(char *line)
{
char *token = NULL;
char **args = NULL;
int size = 64;
int i = 0;
if (line == NULL)
{
return (NULL);
}
args = malloc((size + 2) * sizeof(char *));
if (args == NULL)
return (NULL);
token = strtok(line, " \r\t\n");
while (token != NULL)
{
args[i] = token;
i++;
if (i >= size)
{
size += size;
args = realloc(args, size * sizeof(char *));
if (args == NULL)
return (NULL);
}
token = strtok(NULL, " \t\r\n");
}
args[i] = NULL;
return (args);
}
