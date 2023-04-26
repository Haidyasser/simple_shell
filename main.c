#include "shell.h"

/**
 * main - main function
 * Return: 0
 */

int main(void)
{
	char *command, **args;
	int status = 1;
	int nread; /* number of characters the user types */

	while (status)
	{
		display("$cisfun# ");
		command = read_command(&nread);
		args = split_command(command, &nread);
		status = excute(args);

		free(command);
		free(args);
	}
	return (0);
}

