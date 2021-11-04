#include "dhk.h"
/**
 *path_handler - iterates through PATH variable and concatenates
 *command into it
 *@str: string to concatenate
 *@env: the environment variable
 *
 *Return: pointer to concatenated string
 */
char *path_handler(char *str, char **env)
{
	char *path, *concat;
	path_t *list, *tmp;
	struct stat st;

	if (str == NULL || env == NULL || *env == NULL)
		return (NULL);
	path = _getenv("PATH", env);
	if (path == NULL)
	{
		write(STDERR_FILENO, "PATH not found", 14);
		_exit(0);
	}
	list = create_ll(path);
	if (list == NULL)
	{
		write(STDERR_FILENO, "Issues with PATH", 16);
		_exit(0);
	}
	list = fill_list(path, list);
	tmp = list;
	while (tmp != NULL)
	{
		if (path[0] == ':')
			concat = str_concat("./", str);
		else
			concat = str_concat(tmp->directory, str);
		if (concat == NULL)
			return (NULL);
		if (stat(concat, &st) == 0 && access(concat, X_OK) == 0)
		{
			free_list(list);
			return (concat);
		}
		tmp = tmp->next;
		free(concat);
	}
	free_list(list);
	return (NULL);
}
