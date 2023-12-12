#include "main.h"
/**
 * start_with_slash - function checks if file starts with a slash
 * @ptr: filename to be checked
 * Return: 0 for success and 1 otherwise
 */
int start_with_slash(const char *ptr)
{
	if (ptr != NULL || ptr[0] == '/')
	{
		return (1);
	}

	return (0);
}
