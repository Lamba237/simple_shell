#include "main.h"
/**
 * _strcpy - our own str copy function
 * @dest: destination string
 * @source: source string
 * Return: destination string
 */
char *_strcpy(char *dest, const char *source)
{
	char *OriginalDest = dest;

	if (!dest || !source)
	{
		return (NULL);
	}
	while ((*dest++ = *source++) != '\0')
	{
		/* copy characters until null terminator is encountered */
	}

	return (OriginalDest);
}
