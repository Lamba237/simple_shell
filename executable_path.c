#include "main.h"
/**
 * get_file - gets executable path of a file
 * @path: variable path
 * file_name: executable file
 *
 * Return: returns the full executable file of a file
 */
char *get_file(char *path, char *file_name)
{
	char *token;
	char *copy_path;
	struct stat file_path;
	char *path_buf = NULL;

	copy_path = _strdup(path);
	token = strtok(copy_path, ":");

	while (token)
	{
		if (path_buf)
		{
			free(path_buf);
			path_buf = NULL;
		}
		path_buf = malloc(custom_strlen(token) + custom_strlen(file_name) + 2);
		if (!path_buf)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		_strcpy(path_buf, token);
		Strcat(path_buf, "/");
		Strcat(path_buf, file_name);
		Strcat(path_buf, "\0");
		if (stat(path_buf, &file_path) == 0 && access(path_buf, X_OK) == 0)
		{
			free(copy_path);
			return (path_buf);
		}
		token = strtok(NULL, ":");
	}
	free(copy_path);
	if (path_buf)
		free(path_buf);

	return (NULL);
}
