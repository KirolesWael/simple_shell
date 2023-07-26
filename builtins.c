#include "main.h"
/**
 * builtins - Check and execute the builtins
 *
 * @info: Information about the shell
 * @arguments: Commands and arguments
 *
 * Return: If the command passed is a builtins
 * return _TRUE if not return _FALSE
 **/
int builtins(main_t *info, char **arguments)
{
	int status;

	status = check_builtin(info, arguments);
	if (status == 0)
		return (0);

	return (1);
}


/**
 * check_builtin - Check if the actual command is a builtin_t
 * or not
 *
 * @info: General information about the shell
 * @arguments: Arguments of the command
 *
 * Return: If the command is an actual builtin, return _TRUE
 * if not _FALSE
 **/
int check_builtin(main_t *info, char **arguments)
{
	int i, size;
	builtinfunc_t builtins[] = {
		{"exit", bin_exit},
		{"env", bin_env}
	};

	size = sizeof(builtins) / sizeof(builtins[0]);
	for (i = 0; i < size; i++)
	{
		if (_strcmp(info->command, builtins[i].command) == 0)
		{
			builtins[i].exec(info, arguments);
			return (1);
		}
	}

	return (0);
}
