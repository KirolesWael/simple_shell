#ifndef PRINT_H
#define PRINT_H

int printNormal(char *msg);
int printError(char *msg);
int putChar(char c);
int putCharFD(char c, int fd);
int printFD(char *msg, int fd);

#endif PRINT_H