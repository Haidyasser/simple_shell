#include "shell.h"

#define READ_SIZE 1024

/**
 * _getline - read an entire line from a file descriptor
 * @fd: the file descriptor to read from
 *
 * Return: a pointer to the line read, or NULL if the end of file was reached
 * or an error occurred
 */
char *_getline(const int fd)
{
    static char *line = NULL;
    static size_t bytes_allocated = 0;
    size_t total_bytes = 0, line_length = 0;

    if (fd == -1)
        return (NULL);

    while (1)
    {
        /* Make sure we have enough space in the buffer */
        if (total_bytes >= bytes_allocated - 1)
        {
            bytes_allocated += READ_SIZE;
            line = realloc(line, bytes_allocated);
            if (!line)
                return (NULL);
        }

        /* Read a chunk of data from the file descriptor */
        ssize_t bytes_read = read(fd, line + total_bytes, READ_SIZE);
        if (bytes_read < 0)
            return (NULL);
        if (bytes_read == 0)
        {
            if (total_bytes == 0)
                return (NULL);
            break;
        }

        /* Update the total number of bytes read */
        total_bytes += bytes_read;

        /* Check if we have reached the end of a line */
        line_length = strnlen(line, total_bytes);
        if (line[line_length - 1] == '\n')
            break;
    }

    /* Trim any trailing newlines */
    while (line_length > 0 && (line[line_length - 1] == '\n' || line[line_length - 1] == '\r'))
        line[--line_length] = '\0';

    /* Shrink the buffer to fit the line */
    char *new_line = realloc(line, line_length + 1);
    if (!new_line)
        return (NULL);
    line = new_line;

    return (line_length ? line : NULL);
}

