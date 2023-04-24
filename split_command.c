#include "shell.h"

/**
 * split_command - split a command
 * @command: command to split
 * Return: array of strings
 */

char **split_command(char *command)
{
	char **tokens;
	char *token;
	int bufsize = 64, position = 0;

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}

	token = strtok(command, " \n\t\r\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("realloc error");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " \n\t\r\a");
	}
	tokens[position] = NULL;
	return (tokens);

}
