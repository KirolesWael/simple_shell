#include "main.h"

extern char **environ;

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	int command, id, i;

	char *buffer;
	char *cmd;
	char *arg[512];

	if (argc != 1)
		exit(90);

	while (1)
	{
		if (write(STDOUT_FILENO, "$", 1) == -1)
			exit(90);

		buffer = create_buff();
		command = read(STDIN_FILENO, buffer, 1024);

		if (command == -1 || command == 0)
			exit(91);

		for (i = 0; buffer[i] != '\n'; i++)
			;
		buffer[i] = '\0';
		cmd = buffer;
		arg[0] = cmd;
		arg[1] = NULL;

		if (id != 0)
			id = fork();

		/* if (id == -1)
		// 	exit(80);*/

		if (id == 0)
		{
			int e;
			e = execve(arg[0], arg, environ);
			if (e == -1)
			{
				perror(argv[0]);
			}
		}
		else
		{
			wait(NULL);
			free(buffer);
			continue;
		}

	}

	return (0);
}