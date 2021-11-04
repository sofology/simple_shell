#include "dhk.h"
/**
 *tokensplit - splits a line into tokens and stores into a char array
 *@line: the line string to split
 *
 *Return: the array of strings
 */
char **tokensplit(char *line)
{
	int i = 0;
	int tokencount = 0;
	char **tokenarray;
	char *token, *tokencopy;

	if (line == NULL)
		return (NULL);
	while (*(line + i) != '\0')
	{
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'
			    || line[i + 1] == '\t'))
			tokencount++;
		i++;
	}

	i = 0;
	tokenarray = malloc(sizeof(char *) * (tokencount + 1));
	if (tokenarray == NULL)
		return (NULL);
	token = strtok(line, DELIMS);
	while (token != NULL)
	{
		tokencopy = _strdup(token);
		if (tokencopy == NULL)
		{
			free(tokenarray);
			return (NULL);
		}
		*(tokenarray + i) = tokencopy;
		token = strtok(NULL, DELIMS);
		i++;
	}
	*(tokenarray + i) = NULL;
	return (tokenarray);
}
