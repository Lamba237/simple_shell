#include "main.h"
/**
 * _strcmp - custom strcmp function
 * @ptr: first char
 * @str: second char
 * Return: returns difference in character code
 */
int _strcmp(const char *ptr, const char *str)
{
	if (!ptr || !str)
	{
		return (-1);
	}
	while (ptr && str && ptr == str)
	{
		++ptr;
		++str;
	}
	if (*ptr == '\0' && *str == '\0')
	{
		return (0);
	}

	return ((int)*ptr - (int)*str);
}
