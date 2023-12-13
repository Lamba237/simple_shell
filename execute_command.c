#include "main.h"

/**
 * execute_command - function execute the command
 * @command : passing pointer into our function
 * Return: void
 */
void execute_command(char *command)
{
	pid_t pid, wpid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
	} else if (pid == 0)
	{
		/* Child process*/
		if (execve(command, NULL, NULL) == -1)
		{
			perror("execve");
			_exit(EXIT_FAILURE);
		}
	} else
	{
		/* Parent process*/
		do

		{
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

/**
 * main - :main function
 * Return: 0 upon success
 */

int main(void)
{
	char command[MAX_INPUT_SIZE];

	while (1)
	{
		display_prompt();

		ssize_t nread = read(STDIN_FILENO, command, MAX_INPUT_SIZE);

		if (nread == -1)
		{
			/* Handle end-of-file condition (Ctrl+D)*/
			handle_eof();
		}

		/* Remove newline character*/
		if (nread > 0 && command[nread - 1] == '\n')
		{
			command[nread - 1] = '\0';
		}

		if (strlen(command) > 0)
		{
			execute_command(command);
		}
	}

	return (0);
}
