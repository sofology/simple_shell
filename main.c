#define _GNU_SOURCE
#include <stdio.h>
#include "dhk.h"
/**
  *main - entry point for shell program
  *@ac: the number of arguments passed
  *@av: an array of strings of the arguments passed
  *@env: the current environment
  *
  *Description: function will read a line, break it into tokens, and execute
  *the call, then return to main when end of file is reached
  *Return: 0 when EOF is reached (ie user presses Ctrl + D)
  */
int main(int ac, char **av, char **env)
{
	char *line, *newline;
	size_t len = 0;
	ssize_t characters;
	char **tokenarray;
	int cmdnum = 0;

	(void)ac, (void)av;
	while (1)
	{
		line = NULL;
		len = 0;
		cmdnum++;
		if (isatty(STDIN_FILENO) == 1)
			printprompt();
		signal(SIGINT, ctrlc);
		characters = getline(&line, &len, stdin);
		if (characters == EOF || characters == -1)
			return (ctrld(line));
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		newline = _reallocchar(line);
		if (newline == NULL)
		{
			free(line);
			return (0);
		}
		tokenarray = tokensplit(newline);
		if (tokenarray == NULL)
		{
			free(line);
			free(newline);
			return (0);
		}
		exec(tokenarray, env, av, line, newline, cmdnum);
		free_all(line, newline, tokenarray);
	}
}
