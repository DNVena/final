#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * len_buf - finds the number of tokens
 * @buffer: takes pointer to arguments
 * Return: (integer) number of tokens
 */
int len_buf(char *buffer)
{
	char *lines;
	int num = 0;

	lines = strtok(buffer, " ");
	while (lines != NULL)
	{
		num++;
		lines = strtok(NULL, " ");
	}
	num++;
	return (num);
}

/**
 * tokenize - tokenises arguments
 * @buffer: takes pointer to arguments
 * Return: pointer to array of tokens
 */
char **tokenize(char *buffer)
{
	int i, num, len;
	char *token;
	char **args;
	char *buf_cpy;

	buf_cpy = _strdup(buffer);
	num = len_buf(buf_cpy);
	args = malloc(sizeof(char *) * (num + 1));

	token = strtok(buffer, " \n");
	len = _strlen(token);
	for (i = 0; token != NULL; i++)
	{
		args[i] = malloc(sizeof(char) * (len + 1));
		args[i] = _strcpy(args[i], token);
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;
	free(buf_cpy);
	return (args);
}
