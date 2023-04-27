#include "shell.h"


/**
 * shell_exit - exit the shell
 * @args: array of words in the command line
 * Return: 0
 */

int shell_exit(char **args)
{
	(void)args;
	exit(EXIT_SUCCESS);
}

/**
 * shell_env - print the environment
 * @args: array of words in the command line
 * Return: 1
 */

int shell_env(char **args)
{
	int i;

	if (args[1] == NULL)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			display(environ[i]);
			display("\n");
		}
	}
	else
	{
		for (i = 1; args[i] != NULL; i++)
		{
			display(args[i]);
			display("\n");
		}
	}
	return (1);
}

/**
 * shell_cd - change the current directory
 * @args: array of words in the command line
 * Return: 1
 */

int shell_cd(char **args)
{
	if (args[1] == NULL)
	{
		display("Error: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("Error");
		}
	}
	return (1);
}

int (*built_in_func[]) (char **) = {
	&shell_exit,
	&shell_env,
	&shell_cd
};

/**
 * excute - excute a command in the shell
 * @args: array of words in the command line
 * @av: array of arguments
 * @cnt: number of commands
 * Return: 1
 */

int excute(char **args, char **av, int cnt)
{
	int i, status;
	pid_t pid;
	char *location;
	char *built_in[] = {"exit", "env", "cd"};

	if (args[0] == NULL)
		return (1);
	for (i = 0; i < 3; i++)
		if (_strcmp(args[0], built_in[i]) == 0)
			return ((*built_in_func[i])(args));
	location = get_location(args[0]);
	if (location == NULL)
	{
		display(av[0]);
		display(": ");
		display_number(cnt);
		display(": ");
		display(args[0]);
		display(": not found\n");

		return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(location, args, NULL) == -1)
			perror("Error");
		free(location);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		free(location);
		perror("Error");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	free(location);
	return (1);
}
