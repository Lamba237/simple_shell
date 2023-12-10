#include "main.h"
/**
 *execute_command - function executes
 *commands
 *@command: character string
 *Return: 0 for success and 1 for failure
 */
void execute_command(char *command)
{
	char *args[2];
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		args[0] = command;
		args[1] = NULL;

		execve(args[0], args, NULL);

		/* If execve fails, print an error and exit */
		perror("./shell");
		exit(EXIT_FAILURE);
	} else
	{
		waitpid(child_pid, &status, 0);
	}
}
