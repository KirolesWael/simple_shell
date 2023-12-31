#include "main.h"

/**
 * message_selector - Select the message that match with the error_code
 *
 * @info: General information about the shell
 *
 * Return: Error message
 **/
char *message_selector(main_t info)
{
	int i, n_options;
	err_t messages[] = {
		{"No such file or directory", 3},
		{"Permission denied", 13},
		{"not found", 132},
		{"Illegal number", 133}};

	n_options = sizeof(messages) / sizeof(messages[0]);
	for (i = 0; i < n_options; i++)
		if (info.error == messages[i].code)
			return (messages[i].message);

	return ("");
}

/**
 * error - Print the error
 *
 * @info: General information about the shell
 **/
void error(main_t *info)
{
	char *message;
	char *number;
	char *aux;
	int size_number, size_message;

	number = NULL;
	message = message_selector(*info);
	number = to_string(info->NOCommands);

	size_number = _strlen(number);
	size_message = _strlen(info->argv[0]);

	aux = malloc(size_message + size_number + 3);

	aux = _strcpy(aux, info->argv[0]);
	aux = _strcat(aux, ": ");
	aux = _strcat(aux, number);

	message = jointOfWords(aux, info->command, message, ": ");
	printError(message);

	free(message);
	free(number);
	free(aux);
}

/**
 * error_extra - Print the error with extra information
 *
 * @info: General information about the shell
 * @extra: Extra information
 **/
void error_extra(main_t *info, char *extra)
{
	char *message, *number, *aux, *aux2;
	int size_number, size_message, size_extra;

	number = NULL;
	message = message_selector(*info);
	number = to_string(info->NOCommands);

	size_number = _strlen(number);
	size_message = _strlen(info->argv[0]);
	size_extra = _strlen(extra);

	aux = malloc(size_message + size_number + 3);
	aux = _strcpy(aux, info->argv[0]);
	aux = _strcat(aux, ": ");
	aux = _strcat(aux, number);

	aux2 = malloc(_strlen(message) + size_extra + 3);
	aux2 = _strcpy(aux2, message);
	aux2 = _strcat(aux2, ": ");
	aux2 = _strcat(aux2, extra);

	message = jointOfWords(aux, info->command, aux2, ": ");
	printError(message);

	free(message);
	free(number);
	free(aux);
	free(aux2);
}