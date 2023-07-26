#include "main.h"
#include <string.h>
#include <sys/cdefs.h>
#include <unistd.h>

/**
 * _getenv - Get a environment variable
 *
 * @name: Environment variable to get
 *
 * Return: On success value of @name
 * On error, NULL
 **/
char *_getenv(const char *name)
{
	char **env;
	char *aux, *token, *value;
	int size;

	size = _strlen((char *) name);

	for (env = environ; *env; ++env)
	{
		aux = _strdup(*env);

		token = strtok(aux, "=");
		if (token == NULL)
		{
			free(aux);
			return (NULL);
		}

		if (_strlen(token) != size)
		{
			free(aux);
			continue;
		}

		if (_strcmp((char *) name, aux) == 0)
		{
			token = strtok(NULL, "=");
			value = _strdup(token);

			free(aux);
			return (value);
		}

		free(aux);
	}

	return (NULL);
}

/**
 * which - Find the directory needed
 *
 * @filename: Command received
 * @info: General info about the shell
 *
 * Return: pointer string with found path or NULL in failure.
 */
char *which(char *filename, main_t *info)
{
	char *path, *tempo_path, *token;
	char *slash;
	int size;

	(void) info;

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	token = strtok(path, ":");

	size = _strlen(filename) + 2;
	slash = malloc(size * sizeof(char));
	slash = _strcpy(slash, "/");
	slash = _strcat(slash, filename);

	while (token != NULL)
	{
		tempo_path = malloc(_strlen(token) + size);
		tempo_path = _strcpy(tempo_path, token);
		tempo_path = _strcat(tempo_path, slash);

		if (is_executable(tempo_path) == 1)
		{
			free(slash);
			free(path);
			return (tempo_path);
		}
		token = strtok(NULL, ":");

		free(tempo_path);
	}

	free(path);
	free(slash);

	return (NULL);
}

/**
 * is_current_path -	Check the order of the path
 *
 * @path: PATH to check
 * @info: General infor about the shell
 **/
void is_current_path(char *path, main_t *info)
{
	info->correct_path = 0;

	if (path == NULL)
		return;

	if (path[0] == ':')
		info->correct_path = 1;
}

/**
 * get_full_env - Get all the environment
 **/
void get_full_env(void)
{
	char **tempo;
	int i;

	for (i = 0, tempo = environ; tempo[i] != NULL; i++)
	{
		print(tempo[i]);
		_putchar('\n');
	}
}

/**
 * bin_env - Implementation for the env builtin
 *
 * @info: General information about the shell
 * @arguments: Command
 **/
void bin_env(main_t *info, char **arguments)
{
	(void) info;
	(void) arguments;

	get_full_env();
}