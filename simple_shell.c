#include "main.h"
/**
* main - entry point
* @argv: arguments in the stdin
* @argc: numbers of arguments
*
* Return: 0 for success.
*/

int main(int argc, char **argv)
{
char *line = NULL;
char **tokens;
int status = 0, pathnumb = 0;
(void)argc;
while (1)
{
line = _getline();
if (line == NULL)
{
exit(1);
}
if (line)
{
pathnumb++;
tokens = _strtok(line);
if (tokens == NULL)
free(line);
status = exec(tokens, argv, pathnumb);
free(tokens);
free(line);
if (status == 1)
{
exit(0);
}
}
else
{
if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, "\n", 1);
}
exit(status);
}
}
exit(status);
}
