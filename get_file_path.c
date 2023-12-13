#include "main.h"
/**
 * get_file_path - Gets the full path of a file, including handling command lines with arguments.
 *@name_file: file name
 *
 * Return: the full path of the file
 */
char *get_file_path(char *name_file)
{
	char *path = getenv("PATH");
	char *token;
	struct stat file_path;
	char *path_buf = NULL;

	if (start_with_slash(name_file) && access(name_file, X_OK) == 0)
	{
		return (_strdup(name_file));
	}
	if (!path)
	{
		perror("Error");
		return (NULL);
	}       
	token = strtok(path, ":");
	while (token)
	{       
		if (path_buf)
		{       
			free(path_buf);
			path_buf = NULL;
		}
		path_buf = malloc(custom_strlen(token) + custom_strlen(name_file) + 2);
		if (!path_buf)
		{       
			perror("Error");
			exit(EXIT_FAILURE);
		}       
		_strcpy(path_buf, token);
		Strcat(path_buf, "/");
		Strcat(path_buf, name_file);
		Strcat(path_buf, "\0");
		if (stat(path_buf, &file_path) == 0 && access(path_buf, X_OK) == 0)
		{
			return (path_buf);
		}
		token = strtok(NULL, ":");
	}
	return (NULL);
}
