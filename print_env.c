#include "main.h"
/**
* print_env - display the environment
* @token: pointer
* Return: 0
*/
int print_env(char **token)
{
size_t i = 0;
if (*token)
{
while (environ[i])
{
write(STDOUT_FILENO, environ[i], strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
i++;
}
}
return (0);
}
