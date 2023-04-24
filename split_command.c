#include "shell.h"

/**
 * split_command - split a command
 * @command: command to split
 * Return: array of strings
 */

char **split_command(char *command)
{
        char **words;
        char *token;
        int bufsize = 64, position = 0;

        words = malloc(bufsize * sizeof(char *));
        if (!words)
        {
                perror("malloc error");
                exit(EXIT_FAILURE);
        }

        token = strtok(command, " \n\t\r\a");
        while (token != NULL)
        {
                words[position] = token;
                position++;

                if (position >= bufsize)
                {
                        bufsize += 64;
                        words = realloc(words, bufsize * sizeof(char *));
                        if (!words)
                        {
                                perror("realloc error");
                                exit(EXIT_FAILURE);
                        }
                }

                token = strtok(NULL, " \n\t\r\a");
        }
        words[position] = NULL;
        return (words);

}
