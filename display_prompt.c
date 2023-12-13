#include "main.h"

/**
 * display_prompt - function displays a prompt
 * Return: void
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
