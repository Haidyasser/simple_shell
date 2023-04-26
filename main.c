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
	int status = 1;
	int nread; /* number of characters the user types */

	(void)ac;
	while (status)
	{
		display("$cisfun# ");
		command = read_command(&nread);
		args = split_command(command, &nread);
		status = excute(args, av);

		free(command);
		free(args);
	}
	return (0);
}

