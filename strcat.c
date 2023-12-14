#include "main.h"
/**
 * _strcat - function concatenates a string
 * @str: first
 * @ptr: second
 *
 * Return: concatenated string
 */
char *_strcat(char *str, char *ptr)
{
	char *result;
	size_t len1 = 0, line2 = 0, i = 0;

	if (str == NULL || ptr == NULL)
		return (NULL);

	while (str[len1] != '\0')
	{
		len1++;
	}

	while (ptr[line2] != '\0')
	{
		line2++;
	}
	result = (char *)malloc((len1 + line2 + 1) * sizeof(char));

	/*Check if memory allocation was successful*/
	if (result == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	/* Copy the characters from the first string to the result*/
	for (i = 0; i < len1; i++)
	{
		result[i] = str[i];
	}

	/* Copy the characters from the second string to the result*/
	for (i = 0; i <= line2; i++)
	{
		result[line2 + i] = ptr[i];
	}

	return (result);
}
