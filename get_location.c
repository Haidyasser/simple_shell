#include "shell.h"

/**
 * _getenv - gets the value of an environment variable
 * @name: the name of the environment variable
 * Return: the value of the environment variable
 */

char *_getenv(char *name)
{
	int i, j, name_length;
	char *env;

	for (i = 0; environ[i] != NULL; i++)
	{
		env = environ[i];
		name_length = _strlen(name);

		for (j = 0; j < name_length; j++)
		{
			if (env[j] != name[j])
				break;
		}
		if (j == name_length && env[j] == '=')
		{
			return (env + j + 1);
		}
	}
	return (NULL);
}

/**
 * get_location - gets the location of a command
 * @command: the command to find
 *
 * Return: the location of the command
 */

char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;


	path = _getenv("PATH");
	if (path)
	{
		path_copy = _strdup(path);
		command_length = _strlen(command);
		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			directory_length = _strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);

				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
			return (command);

		return (NULL);
	}

	return (NULL);
}
