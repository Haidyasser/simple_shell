#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if the strings are equal, otherwise the difference
 */

int _strcmp(char *s1, char *s2)
{
        int i;

        for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
        {
                if (s1[i] != s2[i])
                        return (s1[i] - s2[i]);
        }
        return (0);
}

/**
 * _strcpy - copies a string
 * @dest: destination string
 * @src: source string
 * Return: the copied string
 */

char *_strcpy(char *dest, char *src)
{
        int i;

        for (i = 0; src[i] != '\0'; i++)
                dest[i] = src[i];
        dest[i] = '\0';
        return (dest);
}

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: the length of the string
 */

int _strlen(char *s)
{
        int i;

        for (i = 0; s[i] != '\0'; i++)
                ;
        return (i);
}

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 * Return: the duplicated string
 */

char *_strdup(char *str)
{
        char *dup;
        int i;

        if (str == NULL)
                return (NULL);
        dup = malloc(sizeof(char) * (_strlen(str) + 1));
        if (dup == NULL)
                return (NULL);
        for (i = 0; str[i] != '\0'; i++)
                dup[i] = str[i];
        dup[i] = '\0';
        return (dup);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: the concatenated string
 */

char *_strcat(char *dest, char *src)
{
        int i, j;

        for (i = 0; dest[i] != '\0'; i++)
                ;
        for (j = 0; src[j] != '\0'; j++)
                dest[i + j] = src[j];
        dest[i + j] = '\0';
        return (dest);
}

