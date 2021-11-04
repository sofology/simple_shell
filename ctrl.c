#include "dhk.h"
/**
 *ctrld - actions for when Ctrl+D is entered into the shell
 *@line: the main line buffer to free
 *
 *Return: 0 on success
 */
int ctrld(char *line)
{
	free(line);
	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
/**
 *ctrlc - control C handler
 *@signum: the signal number received
 *
 *Return: void
 */
void ctrlc(int signum)
{
	(void)signum;

	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 *printprompt - prints the shell prompt
 *
 *Return: void
 */
void printprompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
