#include "main.h"
/**
* _getline - delimited string input
* Return: NULL
*/
char *_getline(void)
{
char *command = NULL;
size_t len = 0;
int read;
read = getline(&command, &len, stdin);
if (read == -1)
{
free(command);
return (NULL);
}
if (command[read - 1] == '\n')
command[read - 1] = '\0';
return (command);
}
