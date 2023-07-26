#ifndef MAIN_H
#define MIAN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#include <structs.h>
#define NULL ((void *)0)

/*buffer.c*/
char *create_buff();


void sighandler(int sig_num);

/*text*/
/*text_manipulation_1*/
int _strlen(char* msg);
char* _strcat(char* dest, char* src);
char* _strcpy(char* dest, char* src);
char* _strdup(char* str);
int _strcmp(char* s1, char* s2);

/*text_manipulation_2*/
int digits(int n);
char* to_string(int number);
int _isdigit(int c);
int _atoi(char* s);
int contains_letter(char* s);

/*print*/
int printNormal(char* msg);
int printError(char* msg);
int putChar(char c);
int putCharFD(char c, int fd);
int printFD(char* msg, int fd);

/* memory.c */
void* _realloc(void* ptr, size_t old_size, size_t new_size);
void free_memory_p(void* ptr);
void free_memory_pp(void** ptr);

/* error.c */
char* message_selector(general_t info);
void error(general_t* info);
void error_extra(general_t* info, char* extra);

#endif
