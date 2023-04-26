#include "shell.h"

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
		if(command && command[0] == '#')
		{
			free(command);
			continue;
		}
		args = split_command(command, &nread);
		status = excute(args, av, cnt);

		free(command);
		free(args);
	}
	return (0);
}
