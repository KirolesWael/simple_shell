#include "main.h"

/**
 * bin_exit - Implementation of the exit builtin
 * Description: Free all the memory used and
 * exit with the last status_code
 *
 * @info: Information about the shell
 * @arguments: Arguments received
 **/
void bin_exit(main_t *info, char **arguments)
{
	int status_code, status;

	status = 1;
	if (arguments[1] != NULL)
		status = number_controller(info, arguments[1]);

	if (status == 0)
		return;

	status_code = info->status;

	free_memory_pp((void **) arguments);
	free_memory_p((void *) info->buffer);
	free_memory_p((void *) info->environ);
	free_memory_p((void *) info);

	exit(status_code);
}

/**
 * number_controller - Control the argument of exit
 *
 * @info: General information about the shell
 * @number: Argument of the builtin
 *
 * Return: If the actual argument is valid, return 1
 * if not, return 0
 **/
int number_controller(main_t *info, char *number)
{
	int _number;

	_number = _atoi(number);

	if (_number < 0 || contains_letter(number))
	{
		info->status = 2;
		info->error = 133;
		error_extra(info, number);
		return (0);
	}

	if (_number > 255)
		info->status = _number % 256;
	else
		info->status = _number;

	return (1);
}