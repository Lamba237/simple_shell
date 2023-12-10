#include "main.h"
/**
 * custom_strlen - our custom strlen function
 * @str: string to be entered
 * Return: returns length
 */
size_t custom_strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	return (length);
}
