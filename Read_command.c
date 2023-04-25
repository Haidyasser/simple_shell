#include "shell.h"

/**
 * handler - handles the signal
 * @sig: signal
 * Return: void
 */

void handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n>> ", 4);
}

/**
 * read_command - reads the command line
 * @nread: number of characters the user types
 * Return: the command line
 */

char *read_command(int *nread)
{
	char *buf;
	size_t bufsize = 0;

	signal(SIGINT, handler);
	*nread = getline(&buf, &bufsize, stdin);
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
