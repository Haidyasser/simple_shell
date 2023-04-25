#include "shell.h"

/**
 * display - display a string
 * @str: string to display
 * Return: void
 */
void display(char *str)
{
	int len = _strlen(str);

	write(1, str, len);
}
