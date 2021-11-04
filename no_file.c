#include "dhk.h"
/**
 *no_file_er - write an error message if file is not found
 *@argv: the array of passed in function argument strings
 *@ar: the array of tokens entered by the user
 *@cmdnum: the number of commands entered
 *@line: the command line entered by the user
 *@nline: the command line without the newline character
 *
 *Return: void
 */
void no_file_er(char **argv, char **ar, int cmdnum, char *line, char *nline)
{
	char *num;

	num = printint(cmdnum);
	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, num, _strlen(num));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, ar[0], _strlen(ar[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "not found\n", 10);
	free(num);
	free_all(line, nline, ar);
	exit(0);
}
/**
 *printint - prints an integer
 *@num: the number to turn into a string
 *
 *Return: number of characters printed to stdout
 */
char *printint(int num)
{
	int tens = 1;
	int i = 0;
	int tensit = num;
	char *integer;

	integer = malloc(33);
	if (integer == NULL)
		return (NULL);
	if (num == 0)
	{
		integer[i] = 0 + '0';
		return (integer);
	}
	num = num / 10;

	while (num != 0)
	{
		num = num / 10;
		tens *= 10;
	}

	while (tens != 0)
	{
		integer[i] = (tensit / tens) + '0';
		tensit = tensit % tens;
		tens /= 10;
		i++;
	}
	integer[i] = '\0';
	return (integer);
}
