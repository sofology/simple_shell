#include "dhk.h"
/**
 *create_ll - creates an empty linked list the size of the path variable
 *@str: the PATH variable
 *
 *Return: a pointer to the empty array
 */
path_t *create_ll(char *str)
{
	int i = 0;
	int nodes = 1;
	path_t *node, *head, *tmp, *end;

	tmp = malloc(sizeof(path_t));
	if (tmp == NULL)
		return (NULL);
	head = tmp;

	end = malloc(sizeof(path_t));
	if (end == NULL)
	{
		free(tmp);
		return (NULL);
	}
	end->next = NULL;

	while (str[i] != '\0')
	{
		if (str[i] == ':')
			nodes++;
		i++;
	}

	while ((nodes - 2) > 0)
	{
		node = malloc(sizeof(path_t));
		if (node == NULL)
		{
			free(tmp);
			free(end);
			return (NULL);
		}
		tmp->next = node;
		tmp = tmp->next;
		nodes--;
	}
	tmp->next = end;
	return (head);
}
/**
 *fill_list - fills an empty linked list with PATH variable contents
 *@str: the PATH variable
 *@list: pointer to the empty linked list
 *
 *Return: pointer to the filled linked list
 */
path_t *fill_list(char *str, path_t *list)
{
	path_t *ptr, *head;
	char *dir;
	int i = 0, j = 0, stcnt = 0, dirlen = 0;

	if (str ==  NULL || list == NULL)
		return (NULL);
	head = list;
	ptr = head;
	while (ptr != NULL)
	{
		if (str[i] == ':' || str[i] == '\0')
		{
			if (str[i] != '\0')
				i++;
			dir = malloc(sizeof(char) * dirlen + 2);
			if (dir == NULL)
				return (NULL);
			while (str[stcnt] != ':' && str[stcnt] != '\0')
			{
				dir[j] = str[stcnt];
				stcnt++;
				j++;
			}
			dir[j++] = '/';
			dir[j] = '\0';
			stcnt = i;
			j = 0;
			ptr->directory = dir;
			ptr = ptr->next;
		}

		else
		{
			dirlen++;
			i++;
		}
	}
	return (head);
}
