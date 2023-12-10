#include "main.h"


/**
 * _strdup - duplicates a string using malloc
 * @str: The string to duplicate
 *
 * Return: On success, a pointer to the newly allocated string.
 * On failure, terminate the program with an error message.
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *dup_str;

	while (str[len] != '\0')
		len++;

	dup_str = malloc(sizeof(char) * (len + 1));

	if (dup_str == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i <= len; i++)
		dup_str[i] = str[i];

	return dup_str;
}

/**
 * print_string - writes a string to stdout
 * @str: The string to print
 */
void print_string(const char *str)
{
	ssize_t len = 0;
	while (str[len] != '\0')
		len++;
	write(1, str, len);
}

/**
 * main - entry point for the shell program
 * Return: Always 0
 */
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	char *args[2];
	pid_t child_pid;
	int status;

	while (1)
	{
		// Display prompt
		print_string("#cisfun$ ");

		// Read command from user
		if (getline(&buffer, &bufsize, stdin) == -1)
		{
			// Handle end of file (Ctrl+D)
			print_string("\n");
			break;
		}

		// Remove trailing newline
		if (buffer[_strdup(buffer) - 1] == '\n')
		{
			buffer[_strdup(buffer) - 1] = '\0';
		}

		// Fork a child process
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Fork error");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			// Child process
			args[0] = buffer;
			args[1] = NULL;

			// Execute the command
			execve(args[0], args, NULL);

			// If execve fails, print an error and exit
			perror("Command not found");
			exit(EXIT_FAILURE);
		}
		else
		{
			// Parent process
			// Wait for the child process to complete
			waitpid(child_pid, &status, 0);
		}
	}

	// Free allocated memory
	free(buffer);

	return 0;
}
