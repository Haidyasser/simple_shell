#include "shell.h"

/**
 * read_command - read a command
 * Return: command
 */

char *read_command()
{
	char *buf;
	size_t n = 0;
	int status;

	status = getline(&buf, &n, stdin);
	if (status == -1)
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
