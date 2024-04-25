#include "main.h"
/**
* _getline - Read the line and might display the prompt
*
* Return: the line.
*/
char *_getline(void)
{
char *line = NULL;
size_t line_size = 0;
if (isatty(STDIN_FILENO))
{
prompt();
}
if (getline(&line, &line_size, stdin) == -1)
{
free(line);
return (NULL);
}
return (line);
}
