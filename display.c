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

/**
 * display_number - display a number
 * @cnt: number to display
 * Return: void
 */
void display_number(int cnt)
{
	int tmp, digits = 0, i, num;

	tmp = cnt;
	while (tmp != 0)
	{
		digits++;
		tmp /= 10;
	}
	for (i = 0; i < digits; i++)
	{
		num = cnt % 10;
		cnt /= 10;
		num += '0';
		write(1, &num, 1);
	}
}
