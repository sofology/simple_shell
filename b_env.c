#include "main.h"

/**
 * b_env - handles the `env` command (displays environment variables)
 * @params: command arguments
 *
 * Return: command exit status
 */
int b_env(Invokable params)
{
	char **args __attribute__((unused)) = params.args;
	char **env = set_env(NULL, NULL);
	uint env_i = 0;

	while (env[env_i] != NULL)
	{
		put_s(env[env_i++]);
		put_s("\n");
	}
	return (0);
}
