#include "shell.h"

/**
 * execute - execute a command
 * @words: array of words in the command line
 * Return: 1 if success, 0 if fail
 */

int execute(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		return (0);
	}
	else if (pid == 0)
	{
	/* Child process */
	if (execve(args[0], args, NULL) == -1)
	{
		perror("execve error");
		exit(EXIT_FAILURE);
	}
	}
	else
	{
		/* Parent process */
		do {
			if (waitpid(pid, &status, WUNTRACED) == -1)
			{
			perror("waitpid error");
			return (0);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
