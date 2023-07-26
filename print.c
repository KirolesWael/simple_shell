#include "main.h"
/**
 * printNormal - Print a message to STDOUT
 *
 * @msg: Message to print
 *
 * Return: On success number of bytes printed
 * On errror -1, and set the error
 **/
int printNormal(char *msg)
{
    return (printFD(msg, 1));
}
/**
 * printError - Print a message to STDERR
 *
 * @msg: Message to print
 *
 * Return: Number of bytes printed
 **/
int printError(char *msg)
{
    return (printFD(msg, 2));
}
/**
 * putChar - Print a character to STDOUT
 *
 * @c: Character to print
 *
 * Return: On success 1
 * On error -1
 **/
int putChar(char c)
{
    return (write(1, &c, 1));
}
/**
 * putCharFD - Print a character to a specific file
 * descriptor
 *
 * @c: Character to print
 * @fd: Place to print the character
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 **/
int putCharFD(char c, int fd)
{
    return (write(fd, &c, 1));
}
/**
 * printFD - Print a string
 *
 * @msg: Strin to print in the fd specified
 * @fd: File descriptor to print
 *
 * Return: On success numbers of bytes printed.
 * On error, -1 is returned, and errno is set appropriately.
 **/
int printFD(char *msg, int fd)
{
    int size;
    size = _strlen(msg);
    return (write(fd, msg, size));
}