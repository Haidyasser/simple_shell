#include "shell.h"

/**
 * main - main function
 * Return: 0
 */

int main(void)
{
	char *command, **args;
	int status = 1;

	while (status)
	{
		display(">> ");
		command = read_command();
		args = split_command(command);
		status = excute(args);

		free(command);
		free(args);
	}
	return (0);
}

