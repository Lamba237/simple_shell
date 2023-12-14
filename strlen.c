#include "main.h"
/**
 * _strlen - custom strlen
 * @ptr: string
 *
 * Return: returns length;
 */
size_t _strlen(char *ptr)
{
	size_t size = 0;

	while (ptr[size] != '\0')
	{
		size++;
	}
	return (size);
}
