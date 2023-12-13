#include "main.h"

/**
 * handle_eof - Function to handle the end-of-file condition (Ctrl+D)
 */
void handle_eof(void)
{
	write(STDOUT_FILENO, "\n", 1);
	exit(EXIT_SUCCESS);
}
