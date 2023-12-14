#include "main.h"
/**
 * exit_built - exit built in function
 * @args: arguments
 * @argc: argument count
 *
 * Return: 0
 */
int exit_built(const char *args, int argc)
{
	(void)args;

	if (argc > 1)
	{
		write(STDERR_FILENO, "usage: exit\n", 11);
		return (1);
	}
	write(STDOUT_FILENO, "Exiting....\n", 12);

	exit (0);

	return (0);
}
