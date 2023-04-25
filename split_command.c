#include "shell.h"

/**
 * _strcpy - copy a string
 * @dest: destination
 * @src: source
 */

void _strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}

/**
 * split_command - split a command
 * @command: command to split
 * @nread: number of characters the user types
 * Return: array of strings
 */

char **split_command(char *command, int *nread)
{
	char *copied, *token;
	char **args;
	int num_tokens = 0, i;

	copied = malloc(sizeof(char) * (*nread + 1));
	if (copied == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	_strcpy(copied, command);

	token = strtok(copied, delim);
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}

	args = malloc(sizeof(char *) * (num_tokens + 1));
	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(command, delim);
	for (i = 0; i < num_tokens; i++)
	{
		args[i] = token;
		token = strtok(NULL, delim);
	}
	args[i] = NULL;

	free(copied);
	return (args);
}
