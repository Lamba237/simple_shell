#include "main.h"
/**
 * remove_newline - removes newline from a char
 * @str: string
 *
 * Return: nothing
 */
void remove_newline(char *str)
{
	size_t length = custom_strlen(str);

	if (length > 0 && str[length - 1] == '\n') {
		str[length - 1] = '\0';
	}
}
