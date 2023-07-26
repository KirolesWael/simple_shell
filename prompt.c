#include "main.h"

/*
read_prompt -> readProm
start_prompt -> startProm
*/

/**
 * prompt - Print the prompt
 *
 * @info: Struct of general information
 **/
void prompt(main_t *info)
{
	if (info->mode == 0)
		return;

	print("$ ");
}

/**
 *  readProm - Read lines in the prompt
 *
 * Return: Buffer readed or NULL if EOF was found
 **/
char * readProm()
{
	char *buf;
	int res;
	size_t size;

	buf = NULL;

	res = getline(&buf, &size, stdin);

	if (res == EOF)
	{
		free_memory_p((void *) buf);
		return (NULL);
	}

	return (buf);
}

/**
 * startProm - Loop reading text
 *
 * @info: Struct of general information
 *
 * Return: Buffer readed or NULL if EOF was found
 **/
void startProm(main_t *info)
{
	char *buff;
	char **arguments;
	char *path;

	signal(2, sigintHandler);
	while (1)
	{
		prompt(info);

		path = _getenv("PATH");
		is_current_path(path, info);

		info->environ = path;
		buff =  readProm();
		if (buff == NULL)
		{
			print(info->mode == 1 ? "exit\n" : "");
			free(path);
			break;
		}

		info->NOCommands++;
		if (buff[0] != '\n')
		{
			arguments = breakingWords(buff, " \t\n");

			info->argument = arguments;
			info->buffer = buff;
			analyze_patterns(info, arguments);
			analyze(arguments, info, buff);

			free_memory_pp((void *) arguments);
		}

		free_memory_p((void *) buff);
		free_memory_p((void *) path);
	}

}

/**
 * sigintHandler - Handler for SIGINT
 *
 * @sig_num: Unused parameter
 **/
void sigintHandler(int sig_num)
{
	(void) sig_num;

	signal(2, sigintHandler);
	print("\n$ ");
	fflush(stdout);
}
