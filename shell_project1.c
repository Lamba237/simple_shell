#include "main.h"
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

	while (1)
	{
		print_string("#cisfun$ ");

		if (getline(&buffer, &bufsize, stdin) == -1)
		{
			print_string("\n");
			break;
		}

		remove_newline(buffer);
		execute_command(buffer);
	}

	free(buffer);

	return (0);
}
