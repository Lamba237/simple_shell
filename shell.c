#include "main.h"
/**
 * main - main function of our program and contains
 * some important functions such as getline, execve
 * and wait
 *
 * Return: 0 on success and 1 for failure
 */
int main(void)
{
	pid_t pid;
	int status, i;
	char **args;
	char *lineptr = NULL, *token;
	size_t size = 0;
	ssize_t nread;

	while (1)
	{
		write(STDOUT_FILENO, ":) ", 3);
		nread = getline(&lineptr, &size, stdin);
		if (nread == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		token = strtok(lineptr, " \n\t");
		args = malloc(sizeof(char *) * 64);
		i = 0;

		while (token)
		{
			args[i] = token;
			token = strtok(NULL, " \n\t");
			i++;
		}
		args[i] = NULL;
		pid = fork();

		if (pid == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}
	/* freeing all alocated buffers */
	free(lineptr);

	return (0); /* represents succeess */
}
