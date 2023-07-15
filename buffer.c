#include "main.h"
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