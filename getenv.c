#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include "main.h"

/**
 * _getenv - gets environment
 * Return: pointer
 */
char *_getenv(char **envp)
{
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
	char *token, *path;
	int j = 0;
	int arr_len;
	char **tokens;
	char *buf_cpy = (char *)malloc(1024);
	envp = environ;

	path = _getenv(envp);
	strcpy(buf_cpy, path);
	arr_len = len_path(path);
	token = strtok(buf_cpy, ":");
	tokens = malloc(sizeof(char *) * (arr_len + 1));
	while (token != NULL)
	{
		tokens[j++] = token;
		token = strtok(NULL, ":");
	}
	tokens[j] = NULL;
	return (tokens);
}

/**
 * find_path - finds absolute path to command
 * @path: takes pointer to pointer
 * @filename: takes command name
 * Return: pointer
 */
char *find_path(char **path, char *filename)
{
	int i;

	for (i = 0; path != NULL; i++)
	{
		DIR *dir = opendir(path[i]);

		if (dir != NULL)
		{
			struct dirent *entry;

			while ((entry = readdir(dir)) != NULL)
			{
				if (strcmp(entry->d_name, filename) == 0)
				{
					closedir(dir);
					return (path[i]);
				}
			}
			closedir(dir);
		}
	}
	return (NULL);
}

/**
 * command - finds absolute command
 * @path: takes pointer to pointer
 * @filename: takes pointer
 * Return: pointer
 */
char *command(char **path, char *filename)
{
	char *token;
	char *com;
	char *command;
	char s = '/';
	int len;

	token = find_path(path, filename);
	if (token == NULL)
	{
		return (NULL);
	}
	len = strlen(filename);
	com = strncat(token, &s, 1);
	command = strncat(com, filename, len);

	return (command);
}
