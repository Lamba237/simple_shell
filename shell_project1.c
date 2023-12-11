#include "main.h"
/**
 * main - entry point for the shell program
 * Return: Always 0
 */
int main(void)
{
	char *lineptr = NULL;
	size_t size = 0;

	while (1)
	{
		print_string("#cisfun$ ");

		if (getline(&lineptr, &size, stdin) == -1)
		{
			print_string("\n");
			break;
		}

		remove_newline(lineptr);
		execute_command(lineptr);
	}

	free(lineptr);

	return (0);
}
