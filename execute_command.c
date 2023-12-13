#include "main.h"

/**
 * execute_command - function execute the command
 * @command : passing pointer into our function
 * Return: void
 */


void execute_command(char *command)
{
	pid_t pid;
	int status;
	size_t i;

	/* Split the command into arguments*/
	char *token = strtok(command, " \t\n");
	char *args[MAX_ARGS + 1];  /* Additional slot for NULL terminator*/
	size_t arg_count = 0;

	while (token && arg_count < MAX_ARGS)
	{
		args[arg_count++] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	args[arg_count] = NULL;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		/* Child process*/

		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			_exit(EXIT_FAILURE);
		}
	} else
	{
		/* Parent process*/
		waitpid(pid, &status, 0);
	}
	/* Free the dynamically allocated memory for arguments*/
	for (i = 0; i < arg_count; ++i)
	{
		free(args[i]);
	}
}

/**
 * main - :main function
 * Return: 0 upon success
 */

int main(void)
{
	char command[MAX_INPUT_SIZE];
	ssize_t nread;

	while (1)
	{
		display_prompt();

		nread = read(STDIN_FILENO, command, MAX_INPUT_SIZE);

		if (nread == 0)
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
