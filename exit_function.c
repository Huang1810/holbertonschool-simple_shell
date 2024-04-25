#include "main.h"
/**
* exit_function - exit the function
* @token: pointer
* Return: 0
*/
int exit_function(char **token)
{
if (*token)
{
exit(0);
}
return (0);
}
