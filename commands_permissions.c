#include "main.h"
#include "memory.h"

/**
 * analyze - Analyze	the arguments
 *
 * @arguments: Commands and arguments to execute
 * @info: General information about the shell
 * @buff: Line readed
 **/
void analyze(char **arguments, main_t *info, char *buff)
{
	char *cmd;
	int status;

	if (*arguments == NULL || arguments == NULL)
		return;

	cmd = arguments[0];
	info->command = cmd;
	if (check_builtin(info, arguments) == 1)
		return;

	status = is_file(cmd);
	if (status == -1)
	{
		info->status = 126;
		info->error = 13;
		error(info);
		return;
	}

	if (status == 1)
	{
		execute(cmd, arguments, info, buff);
		return;
	}

	if (current_directory(cmd, arguments, buff, info) == 1)
		return;

	info->path = which(cmd, info);
	if (info->path != NULL)
	{
		execute(info->path, arguments, info, buff);
		free_memory_p((void *) info->path);
		return;
	}

	info->status = 127;
	info->error = 132;
	error(info);
}


/**
 * is_executable - Check if a filename have permissions
 * for run
 *
 * @filename: Filename to check
 *
 * Return: On success, 1
 * On error, -1
 **/
int is_executable(char *filename)
{
	struct stat stats;

	if (stat(filename, &stats) == 0)
	{
		if (stats.st_mode & 1)
			return (1);
		else
			return (-1);
	}

	return (-10);
}

/**
 * is_file - Check if is a file or binary
 * Description: Lool for excute permissions and
 * if is a file
 *
 * @file: File to check
 *
 * Return: If is a file with the correct permissions, 1
 * If is a file but not have permissions or doesn't exists, -1
 * If is not a file, -10
 **/
int is_file(char *file)
{
	int i, size;

	size = _strlen(file);
	for (i = 0; i < size; i++)
		if (file[i] == '/')
			return (is_executable(file));

	return (-10);
}
