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

#define NULL ((void *)0)

/*structs*/
typedef struct __attribute__((__packed__))
{
	int argc;
	char **argv;
	int mode;
	int error;
	char *command;
	int NOCommands;
	char *path;
	int correct_path;
	int status;
	char *buffer;
	char **argument;
	char *environ;
	int PID;
} main_t;

typedef struct __attribute__((__packed__))
{
	char *message;
	int code;
} err_t;

typedef struct __attribute__((__packed__))
{
	char *command;
	void (*exec)(main_t *info, char **argunemt);
} builtinfunc_t;

extern char **environ;

/*text_manipulation_1*/
int _strlen(char *msg);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

/*text_manipulation_2*/
int digits(int n);
char *to_string(int number);
int _isdigit(int c);
int _atoi(char *s);
int contains_letter(char *s);

/* memory.c */
void *_realloc(void *ptr, size_t old_size, size_t new_size);
void free_memory_p(void *ptr);
void free_memory_pp(void **ptr);

/* error.c */
char *message_selector(main_t info);
void error(main_t *info);
void error_extra(main_t *info, char *extra);

/* builtins.c */
int builtins(main_t *info, char **arguments);
int check_builtin(main_t *info, char **arguments);

/* exit.c */
void bin_exit(main_t *info, char **arguments);
int number_controller(main_t *info, char *number);

/* commands_permissions.c */
void analyze(char **arguments, main_t *info, char *buff);
int is_executable(char *filename);
int is_file(char *command);

/* environment.c */
char *_getenv(const char *name);
char *which(char *filename, main_t *info);
void is_current_path(char *path, main_t *info);
void get_full_env(void);
void bin_env(main_t *info, char **arguments);

/* execute.c */
void execute(char *commands, char **arguments, main_t *info, char *buff);
int current_directory(char *cmd, char **arguments, char *buff, main_t *info);

/* prompt.c */
void startProm(main_t *info);
void prompt(main_t *info);
char *readProm();
void sigintHandler(int sig_num);

/* print.c */
int putChar_to_fd(char l, int fd);
int printFD(char *msg, int fd);
int putChar(char c);
int printNormal(char *msg);
int printError(char *msg);

/* token.c */
char **breakingWords(char *line, const char *separted);
char *jointOfWords(char *word1, char *word2, char *word3, const char *sep);

/* patterns.c */
void analyze_patterns(main_t *info, char **arguments);
char *pattern_handler(main_t *info, char *string);
char *replace_value(main_t *info, int *index, char *string);
char *replacement(main_t *info, int *index, char *string);
char *replace_env(main_t *info, char *environment);

#endif
