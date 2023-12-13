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
	int status, i = 0;
	char **Args;

	while (1)
	{
		print_string("Cisfun$ ");
		nread = getline(&lineptr, &count, stdin);
		remove_newline(lineptr);
		if (nread == -1)
		{
			perror("Error");
			exit(0);
		}
		token = strtok(lineptr, " \n\t");
		Args = malloc(sizeof(char *) * 1024);
		while (token)
		{
			Args[i] = token;
			token = strtok(NULL, " \n\t");
			i++;
		}
		Args[i] = NULL;
		path = get_file_path(Args[0]); /* get the absolute path */
		if (path == NULL)
		{
			free(Args);
			continue;
		}
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Fork error");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			if (execve(path, Args, NULL))
			{
				/* If execve fails, print an error and exit */
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(child_pid, &status, 0);
		}
		free(path);
		free(Args);
	}
	free(lineptr);
	return (0);
}
