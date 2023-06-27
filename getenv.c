#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include "main.h"

/**
 * _getenv - gets environment
 * Return: pointer
 */
char *_getenv()
{
	char **envp = environ;
	char *name = "PATH";
	char *path;
	int len;

	len = strlen(name);

	while (*envp != NULL)
	{
		if (strncmp(*envp, name, len) == 0 && (*envp)[len] == '=')
		{
			path = &((*envp)[len + 1]);
		}
		envp++;
	}
	return (path);
}

/**
 * len_path - finds the length
 * @buffer: takes a pointer
 * Return: integer
 */
int len_path(char *buffer)
{
	char *lines;
	int num = 0;

	lines = strtok(buffer, ":");
	while (lines != NULL)
	{
		num++;
		lines = strtok(NULL, ":");
	}
	return (num);
}

/**
 * sep_path - tokenizes path
 * @envp: takes a pointer
 * Return: pointer to a pointer
 */
char **sep_path(char **envp)
{
	char *buf_cpy;
	char *token, *path;
	int j = 0;
	int arr_len;
	char **tokens;

	path = _getenv();
	buf_cpy = strdup(path);
	arr_len = len_path(buf_cpy);
	token = strtok(path, ":");
	tokens = malloc(sizeof(char *) * (arr_len + 1));
	while (token != NULL)
	{
		tokens[j++] = token;
		token = strtok(NULL, ":");
	}
	tokens[j] = NULL;
	free(buf_cpy);
	return (tokens);
}
