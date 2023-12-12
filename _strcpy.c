#include "main.h"
/**
 * _strcpy - our own str copy function
 * @dest: destination string
 * @source: source string
 * Return: destination string
 */
char *_strcpy(char *dest, char *source)
{
	if (!dest || !source)
	{
		return (NULL);
	}
	while (source)
	{
		dest = source;
		++dest;
		++source;
	}
	dest = '\0';

	return (dest);
}
