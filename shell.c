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
	char *path;
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
			perror("./shell");
			exit(0);
		}
		if (lineptr[nread - 1] == '\n')
		{
			lineptr[nread - 1] = '\0';
		}
		token = strtok(lineptr, " \n\t");
		args = malloc(sizeof(char *) * 1024);
		i = 0;

		while (token)
		{
			args[i] = token;
			token = strtok(NULL, " \n\t");
			i++;
		}
		args[i] = NULL;
		path = get_file_path(args[0]);

		if (path == NULL)
		{
			continue;
		}

		pid = fork();

		if (pid == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (execve(path, args, NULL) == -1)
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
	free(path);

	free(lineptr);

	return (0); /* represents succeess */
}
