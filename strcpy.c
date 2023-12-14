#include "main.h"
/**
 * _strcpy - copies a string
 * @dest: destination string
 * @source: source string
 *
 * Return: returns the destination string
 */
char *_strcpy(char *dest, char *source)
{
	size_t len = 0;

	if (dest == NULL || source == NULL)
		return (NULL);

	while (source[len] != '\0')
	{
		dest[len] = source[len];
		len++;
	}
	dest[len] = '\0';

	return (dest);
}
