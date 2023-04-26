#include "shell.h"

/**
 * _getline - read a line of input from stdin
 * @line: pointer to a pointer to a string
 *
 * Return: number of characters read, or -1 on error or end of input
 */
ssize_t _getline(char **line)
{
        ssize_t nread = 0;
        size_t bytes_allocated = 0, total_bytes = 0;
        char *buffer = NULL;

        if (line == NULL)
                return (-1);

        buffer = malloc(sizeof(char) * READ_SIZE);
        if (buffer == NULL)
                return (-1);

        while (1)
        {
                /* If the buffer is full, reallocate it */
                if (total_bytes >= bytes_allocated - 1)
                {
                        bytes_allocated += READ_SIZE;
                        char *new_buffer = realloc(buffer, bytes_allocated);
                        if (new_buffer == NULL)
                        {
                                free(buffer);
                                return (-1);
                        }
                        buffer = new_buffer;
                }

                /* Read a chunk of data from stdin */
                nread = read(STDIN_FILENO, buffer + total_bytes, READ_SIZE);
                if (nread < 0)
                {
                        free(buffer);
                        return (-1);
                }
                else if (nread == 0)
                {
                        /* End of input */
                        if (total_bytes == 0)
                        {
                                free(buffer);
                                return (-1);
                        }
                        break;
                }

                /* Update the total number of bytes read */
                total_bytes += nread;

                /* Check if we have reached the end of a line */
                if (memchr(buffer + total_bytes - nread, '\n', nread) != NULL)
                        break;
        }

        /* Trim any trailing newlines */
        while (total_bytes > 0 && (buffer[total_bytes - 1] == '\n' || buffer[total_bytes - 1] == '\r'))
                total_bytes--;

        /* Shrink the buffer to fit the line */
        char *new_line = realloc(buffer, total_bytes + 1);
        if (new_line == NULL)
        {
                free(buffer);
                return (-1);
        }
        new_line[total_bytes] = '\0';

        *line = new_line;

        return (total_bytes);
}

