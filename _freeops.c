#include "dhk.h"
/**
 *free_all - frees all of the variables used
 *@line: the original line entered by user
 *@newline: line truncated to remove new line char
 *@tokenarray: array of token strings
 *
 *Return: void
 */
void free_all(char *line, char *newline, char **tokenarray)
{
	free_tokens(tokenarray);
	free(line);
	free(newline);
	free(tokenarray);
}
/**
 *free_list - frees a list_t list
 *@head: head of the linked list
 *
 *Return: void
 */
void free_list(path_t *head)
{
	path_t *nextnode;

	while (head != NULL)
	{
		nextnode = head->next;
		free(head->directory);
		free(head);
		head = nextnode;
	}
}
/**
 *free_tokens - frees the tokens in the tokenarray
 *@tokenarray: array of tokens
 *
 *Return: void
 */
void free_tokens(char **tokenarray)
{
	int i = 0;

	while (tokenarray[i] != NULL)
	{
		free(tokenarray[i]);
		i++;
	}
	free(tokenarray[i]);
}
