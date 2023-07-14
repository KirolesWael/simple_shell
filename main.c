#include "main.h"

extern char **environ;

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main()
{
	int command, id, i;
	char *buffer;
	char *cmd;
	char *arg[512];
	signal(SIGINT, sighandler);
	while (1)
	{
		if (write(STDOUT_FILENO, "$", 1) == -1)
		{
			exit(90);
		}
		buffer = create_buff();
		command = read(STDIN_FILENO, buffer, 1024);
		if (command == -1 || command == EOF)
		{
			exit(91);
		}
		for (i = 0; buffer[i] != '\n'; i++);
		buffer[i] = '\0';
		cmd = buffer;
		arg[0] = cmd;
		arg[1] = NULL;

		id = fork();

		if (id == -1)
			exit(80);

		if (id == 0)
		{
			int e;
			e = execve(arg[0], arg, environ);
			if (e == -1)
				perror("./shell");
		}
		else
		{
			wait(NULL);
			continue;
		}
		
	}

	return (0);
}

/**
  *create_buffer
  *
  *Return: buffer
  */
char *create_buff()
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (!buffer)
		exit(90);
	return (buffer);
}
/**
 * sighandler(int signum)
 *
 * Return: void.
 */
void sighandler(int signum)
{
	signal(SIGINT, sighandler);
	printf("Stopped: %d\n", signum);
}


