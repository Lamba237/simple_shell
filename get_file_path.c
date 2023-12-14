#include "main.h"
/**
 * get_file_path - function gets full path of file
 * @file_name: file name to be use
 *
 * Return: returns full path
 */
char *get_file_path(char *file_name)
{
	char *path = getenv("PATH");
	char *full_path;

	if (startsWithForwardSlash(file_name) &&
			access(file_name, X_OK) == 0)
		return (strdup(file_name));

	if (!path)
	{
		perror("Path not found");
		return (NULL);
	}

	full_path = get_file_loc(path, file_name);

	if (full_path == NULL)
	{
		write(2, file_name, strlen(file_name));
		write(2, ": command not found\n", 19);
		return (NULL);
	}

	return (full_path);
}
