#include "shell.h"


/**
 * _getline - Read an entire line from a file descriptor
 * @lineptr: Pointer to a buffer where the line will be stored
 * @n: Pointer to the size of the buffer
 * @fd: File descriptor to read from
 * Return: Number of bytes read, or -1 on failure
 */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
    char *buffer = NULL;
    size_t input = 0, capacity = 0;
    ssize_t count;

    if (!lineptr || !n)
        return (-1);

    do {
        if (input == capacity)
        {
            capacity = capacity * 2 + 1;
            buffer = realloc(buffer, capacity);
            if (!buffer)
                return (-1);
        }

        count = read(fd, buffer + input, capacity - input);
        if (count < 0)
        {
            free(buffer);
            return (-1);
        }
        input += count;
    } while (count > 0 && buffer[input - 1] != '\n');

    if (input == 0)
        return (-1);

    if (buffer[input - 1] == '\n')
        input--;

    buffer[input] = '\0';

    assign_lineptr(lineptr, n, buffer, input);

    return (input);
}

/**
 * assign_lineptr - Assign a new line buffer to a pointer
 * @lineptr: Pointer to a buffer pointer
 * @n: Pointer to the size of the buffer
 * @buffer: Pointer to the new buffer
 * @b: Size of the new buffer
 */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
    if (!lineptr || !n || !buffer)
        return;

    if (*lineptr)
        free(*lineptr);

    *lineptr = buffer;
    *n = b;
}

