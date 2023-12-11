#include "main.h"
#define ARGS_MAX 64
/**
 * parse_Arg - handles parsed arguments
 *
 * @command: string to be parsed
 * Return: a paesed string
 */
char **parse_Arg(char *command)
{
	char *token;
	int count = 0;
	char **args = (char **)malloc(sizeof(char *) * (ARGS_MAX + 1));

	if (args == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	token = strtok(command, " \n\t");
	while (token != NULL)
	{
		args[count] = _strdup(token);
		if (args[count] == NULL)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		count++;
		/*check if max args is obtained */
		if (count >= ARGS_MAX)
		{
			perror("arguments reached");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " \n\t");
	}
	args[count] = NULL;
	return (args);
}
