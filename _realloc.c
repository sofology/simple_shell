#include "dhk.h"
/**
 *_realloccharss - reallocates memory for char**
 *@ptr: a pointer to an array
 *@n: number of elements to add/subtract
 *
 *Return: pointer to new memory
 */
char **_realloccharss(char **ptr, int n)
{
	int i = 0;
	int newsize;
	char **newptr;

	if (ptr == NULL || *ptr == NULL)
		return (NULL);

	while (*(ptr + i) != NULL)
		i++;

	newsize = i + n;
	newptr = malloc(sizeof(char *) * newsize + 1);
	if (newptr == NULL)
		return (NULL);
	i = 0;
	while (*(ptr + i) != NULL)
	{
		*(newptr + i) = *(ptr + i);
		i++;
	}
	*(newptr + i) = NULL;
	return (newptr);
}

/**
 *_reallocchar - reallocates memory for char
 *@ptr: a pointer to an array
 *
 *Return: pointer to new memory
 */
char *_reallocchar(char *ptr)
{
	int i = 0;
	char *newptr;

	if (ptr == NULL)
		return (NULL);

	while (*(ptr + i) != '\n')
		i++;

	newptr = malloc(sizeof(char) * i + 1);
	if (newptr == NULL)
		return (NULL);
	i = 0;
	while (*(ptr + i) != '\n')
	{
		*(newptr + i) = *(ptr + i);
		i++;
	}
	*(newptr + i) = '\0';
	return (newptr);
}
