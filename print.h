#ifndef PRINT_H
#define PRINT_H


int putChar_to_fd(char c, int fd);
int _putChar(char c);
int print(char *msg);
int print_to_fd(char *msg, int fd);
int print_err(char *msg);

#endif PRINT_H