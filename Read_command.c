#include "shell.h"

/**
 * read_command - reads the command line
 * @nread: number of characters the user types
 * Return: the command line
 */

char *read_command(int *nread)
{
	char *buf;

	*nread = _getline(&buf);
	if (*nread == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	return (buf);
}
