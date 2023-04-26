#include "shell.h"

void handlec(int sig)
{
	signal(sig, handlec);
	write(1, "\n>> ", 4);
}

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
	char *buf = NULL;
	size_t bufsize = 0;

	/*signal(SIGINT, handler);*/
	*nread = getline(&buf, &bufsize, stdin);
	if (*nread == -1)
	{
		if (feof(stdin))
		{
			free(buf);
			write(1, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		perror("readline");
		exit(EXIT_FAILURE);
	}
	return (buf);
}
