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
	int i;
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

	for (i = 0; i <= len; i++)
		dup_str[i] = str[i];

	dup_str[len] = '\0';

	return (dup_str);
}
