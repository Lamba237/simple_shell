#include "main.h"
/**
 * _strdup - custom string dup function
 * @ptr: string to be duplicated
 * Return: a pointer
 */
char *_strdup(char *ptr)
{
	size_t size = 0, i;
	char *newstr;

	if (ptr == NULL)
		return (NULL);

	while (ptr[size] != '\0')
	{
		size++;
	}
	newstr = (char *)malloc((size + 1) * sizeof(char *));
	if (newstr == NULL)
	{
		perror("Memory error");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i <= size; i++)
	{
		newstr[i] = ptr[i];
	}
	return (newstr);
}
