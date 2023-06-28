#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - runs simple shell
 * Return: Always (0)
 */
int main(void)
{
	char **args, **envp, **path, *buffer = NULL, *prompt = "$ ";
	ssize_t result;
	size_t len = 0;
	pid_t pid;

	envp = environ;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			_putchar(prompt[0]);
			_putchar(prompt[1]);
		result = getline(&buffer, &len, stdin);
		if (result == -1)
		{
			break;
		}
		else
		{
			path = sep_path(envp);
			args = prep(buffer, path);
			if (args == NULL)
			{
				perror("Did not find command");
			}
			else
			{
				pid = fork();
				if (pid == -1)
					return (-1);
				if (pid == 0)
					_exec(args, envp);
				else
					wait(NULL);
			}
			free(path);
			free(args);
		}
	}
	free(buffer);
	return (0);
}
