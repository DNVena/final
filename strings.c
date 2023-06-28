#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * _strlen - finds the length of a string
 * @str: takes a character pointer
 * Return: Always 0
 */

int _strlen(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		return (0);
	}

	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

/**
 * _strcpy - Copy a string
 * @dest: Destination value
 * @src: Source value
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)

{
	int i;

	if (dest == src | src == 0)
	{
		return (dest);
	}

	for (i = 0; src[i] != '\0'; i++)
	{
	dest[i] = src[i];
	}
	dest[i++] = '\0';
	return (dest);
}

/**
 * _strdup - it returns a pointer to a new string
 * which is a copy of the string.
 * @str: string that should be be copied.
 * Return: NULL, if str = NULL
 */

char *_strdup(char *str)
{
	int e = 0, t = 1;
	char *h;

	if (str == NULL)
		return (NULL);

	while (str[t])
	{
		t++;
	}

	h = malloc((sizeof(char) * t) + 1);

	if (h == NULL)
		return (NULL);

	while (e < t)
	{
		h[e] = str[e];
		e++;
	}
	h[e] = '\0';
	return (h);
}

/**
 * _strncat - concatenates 2 strings
 * @dest: takes character pointer
 * @src: takes character pointer
 * @n: takes an integer
 * Return: Always 0
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - compares 2 strings
 * @s1: takes character pointer
 * @s2: takes character pointer
 * Return: Always 0
 */
int _strcmp(char *s1, char *s2)
{
	int com;

	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		com = 0;
	}
	else if (*s1 < *s2)
	{
		com = -1;
	}
	else
	{
		com = 1;
	}
	return (com);
}
