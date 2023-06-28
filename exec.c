#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * prep - prepares arguments
 * @buffer: takes pointer
 * Return: pointer to pointer
 */
char **prep(char *buffer, char **path)
{
	char **tokens, **args;

	tokens = tokenize(buffer);
	args = checker(path, tokens);

	return (args);
}

/**
 * _exec - executes commands
 * @args: takes pointer to array of arguments
 * @envp: takes pointet to pointer
 * Return: void
 */
void _exec(char **args, char **envp)
{
	if (execve(args[0], args, envp) == -1)
	{
		perror("Error: Can't");
	}
}
