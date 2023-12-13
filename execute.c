#include "main.h"
/**
 *execute_command - function executes
 *commands
 *@command: character string
 *Return: 0 for success and 1 for failure
 */
int main(void)
{
	char *lineptr = NULL, *token, *path;
	ssize_t nread;
	size_t count;
	pid_t child_pid;
	int status, i;
	char **Args;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#Cisfun", 9);

		nread = getline(&lineptr, &count, stdin);
		remove_newline(lineptr);
		if (nread == -1)
		{
			exit(0);
		}
		token = strtok(lineptr, " \n\t");
		Args = malloc(sizeof(char *) * 1024);

		i = 0;
		while (token)
		{
			Args[i] = token;
			token = strtok(NULL, " \n");
			i++;
		}
		Args[i] = NULL;
		path = get_file_path(Args[0]); /* get the absolute path */

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Fork error");
			exit(41);
		}

		if (child_pid == 0)
		{
			if (execve(path, Args, NULL) == -1)
			{
				/* If execve fails, print an error and exit */
				perror("./shell");
				exit(97);
			}
		}
		else
		{
			wait(&status);
		}
	}
	free(path);
	free(lineptr);
	return (0);
}
