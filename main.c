#include "shell.h"

/**
 * handle_comments - handle comments
 * @command: command to handle
 * Return: command without comments
 */

char *handle_comments(char *command)
{
	int i = 0;

	if (command == NULL)
		return (NULL);
	while (command[i] != '\0')
	{
		if (command[i] == '#')
		{
			command[i] = '\0';
			break;
		}
		i++;
	}

	return (command);
}

/**
 * main - main function
 * @ac: number of arguments
 * @av: array of arguments
 * Return: 0
 */

int main(int ac, char **av)
{
	char *command, **args;
	int status = 1, cnt = 0;
	int nread; /* number of characters the user types */

	(void)ac;
	while (status)
	{
		if (isatty(STDIN_FILENO))
			display("$ ");
		signal(SIGINT, handler);
		cnt++;
		command = read_command(&nread);
		command = handle_comments(command);
		args = split_command(command, &nread);
		status = excute(args, av, cnt);

		free(command);
		free(args);
	}
	return (0);
}
