#include "main.h"
/**
 * print_string - function that prints a string
 * to standard output or console
 * @str: string to be printed
 *
 * Return: nothing
 */
void print_string(const char *str)
{
	ssize_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	write(1, str, len);
}
