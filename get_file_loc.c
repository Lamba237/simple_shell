#include "main.h"
/**
 * get_file_loc - gets executable path of a file
 * @path: full path
 *
 * @file_name: file name
 * Return: returns executable
 */
char *get_file_loc(char *path, char *file_name)
{
	/* initialization */
	char *path_copy, *token;
	struct stat file_path;
	char *path_buffer = NULL;

	/* declaration of variables*/
	path_copy = _strdup(path);
	token = strtok(path_copy, ":");

	while (token)
	{
		if (path_buffer)
		{
			free(path_buffer);
			path_buffer = NULL;
		}
		path_buffer = malloc(_strlen(token) + _strlen(file_name) + 2);
		if (!path_buffer)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		_strcpy(path_buffer, token);
		strcat(path_buffer, "/");
		strcat(path_buffer, file_name);
		strcat(path_buffer, "\0");

		if (stat(path_buffer, &file_path) == 0 && access(path_buffer, X_OK) == 0)
		{
			free(path_copy);
			return (path_buffer);
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	if (path_buffer)
		free(path_buffer);
	return (NULL);
}
