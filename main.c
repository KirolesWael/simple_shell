#include "main.h"

/**
 * main - Entry Point
 * @argc: number of arguments received
 * @argv: arguments received
 * Return: 0
 **/

int main(int argc, char **argv)
{
	main_t *info;
	int status_code;

	info = malloc(sizeof(main_t));
	if (info == NULL)
	{
		perror(argv[0]);
		exit(1);
	}

	info->PID = getpid();
	info->status = 0;
	info->NOCommands = 0;
	info->argc = argc;
	info->argv = argv;
	info->mode = isatty(0) == 1;
	startProm(info);

	status_code = info->status;

	free(info);

	return (status_code);
}