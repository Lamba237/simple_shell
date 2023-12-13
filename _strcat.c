#include "main.h"
/**
 * custom_strcat - concatenates two strings using malloc
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to the concatenated string
 */
char *Strcat(const char *dest, const char *src)
{
	size_t dest_len = custom_strlen(dest);
	size_t src_len = custom_strlen(src);
	char *result;

	if (dest == NULL || src == NULL)
	{
		return NULL;
	}
	result = (char *)malloc(dest_len + src_len + 1);
	if (result == NULL)
	{
		return NULL;
	}

	_strcpy(result, dest);
	_strcpy(result + dest_len, src);

	return result;
}

