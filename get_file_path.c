#include "main.h"
/**
 * get_file_path - Gets the full path of a file, including handling command lines with arguments.
 *@name_file: file name
 *
 * Return: the full path of the file
 */
char *get_file_path(char *name_file)
{
	char *full_path;
	char *path = getenv("PATH");

	if (start_with_slash(name_file) && access(name_file, X_OK) == 0)
	{
		return (_strdup(name_file));
	}
	if (!path)
	{
		perror("Error");
		return (NULL);
	}
	full_path = get_file(path, name_file);
	if (full_path == NULL)
	{
		write(2, name_file, custom_strlen(name_file));
		write(2, ": command not found", 19);
		return (NULL);
	}
	return (full_path);
}
