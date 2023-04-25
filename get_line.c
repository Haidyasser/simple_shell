#include "shell.h"
<<<<<<< HEAD
=======

>>>>>>> 39d25c9 (betty style)
/**
 * _getline - get a line from stdin
 * @line: pointer to a pointer to a string
 * Return: number of characters read
 * On error: -1 inapropiate entry
 */
<<<<<<< HEAD
int _getline(char **line)
{
        int i = 0, size = 0, nread = 0;
        char *buffer = NULL;
        if (line == NULL)
                return (-1);
        buffer = malloc(sizeof(char) * 1024);
        if (buffer == NULL)
                return (-1);
        nread = read(STDIN_FILENO, buffer, 1024);
        if (nread == 0)
        {
                free(buffer);
                return (-1);
        }
        while (buffer[i] != '\n')
        {
                i++;
                size++;
        }
        *line = malloc(sizeof(char) * (size + 1));
        if (*line == NULL)
        {
                free(buffer);
                return (-1);
        }
        _strncpy(*line, buffer, size);
        free(buffer);
        return (size);
}







=======

int _getline(char **line)
{
	int i = 0, size = 0, nread = 0;
	char *buffer = NULL;

	if (line == NULL)
		return (-1);
	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return (-1);
	nread = read(STDIN_FILENO, buffer, 1024);
	if (nread == 0)
	{
		free(buffer);
		return (-1);
	}
	while (buffer[i] != '\n')
	{
		i++;
		size++;
	}
	*line = malloc(sizeof(char) * (size + 1));
	if (*line == NULL)
	{
		free(buffer);
		return (-1);
	}
	_strncpy(*line, buffer, size);
	free(buffer);
	return (size);
}
>>>>>>> 39d25c9 (betty style)
