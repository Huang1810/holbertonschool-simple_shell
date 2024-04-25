#include "main.h"
/**
*  builtin - verify if the token is an argument
* @token: pointer from _strtok
*
* Return: 1 or 0
*/
int builtin(char **token)
{
char *builtin_func_list[] = {
"env",
"exit",
"^D"
};
int (*builtin_func[])(char **) = {
&print_env,
&exit_function,
&eof,
};
unsigned long int i = 0;
for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
{
if (strcmp(token[0], builtin_func_list[i]) == 0)
{
return ((*builtin_func[i])(token));
}
}
return (0);
}
