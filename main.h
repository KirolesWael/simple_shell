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

#define _TRUE            1
#define _FALSE           0

#define STDIN            0
#define STDOUT           1
#define STDERR           2

#define NON_INTERACTIVE  0
#define INTERACTIVE      1

#define PERMISSIONS      1
#define NON_PERMISSIONS -1

#define _FILE            10
#define NON_FILE         -10

#define _ENOENT          "No such file or directory"
#define _EACCES          "Permission denied"
#define _CMD_NOT_EXISTS  "not found"
#define _ILLEGAL_NUMBER  "Illegal number"

#define _CODE_ENOENT           3
#define _CODE_EACCES           13
#define _CODE_CMD_NOT_EXISTS   132
#define _CODE_ILLEGAL_NUMBER   133
typedef struct __attribute__((__packed__))
{
	int argc;                 /* Number of arguments received */
	char** argv;              /* Arguments received */
	int mode;                 /* INTERACTIVE or NON_INTERACTIVE */
	int error_code;           /* Error code for error message */
	char* command;            /* Command to execute */
	int n_commands;           /* Number of commands executed */
	char* value_path;         /* Path of a command */
	int is_current_path;      /* Check if is current path or not */
	int status_code;          /* Last exit code */
	char* buffer;             /* Line readed with the getline */
	char** arguments;         /* Line splited into words */
	char* environment;        /* Last environment variable get it */
	int pid;                  /* Process id */
} general_t;

typedef struct __attribute__((__packed__))
{
	char* message;            /* Error message */
	int code;                 /* Error code for identify the error message */
} error_t;

typedef struct __attribute__((__packed__))
{
	char* command;            /* arguments[0] = cmd */
	void (*func)(general_t * info, char** arguments);
} builtin_t;

/*buffer.c*/
char *create_buff();


void sighandler(int sig_num);


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

/* builtins.c */
int builtins(general_t* info, char** arguments);
int check_builtin(general_t* info, char** arguments);

/* exit.c */
void bin_exit(general_t* info, char** arguments);
int number_controller(general_t* info, char* number);

/* env.c */
void bin_env(general_t* info, char** arguments);

/* echo.c */
void bin_echo(general_t* info, char** arguments);
void echo_printer(int index, char* text, char** arguments);

extern char** environ;

/* commands.c */
void analyze(char** arguments, general_t* info, char* buff);

/* permissions.c */
int is_executable(char* filename);
int is_file(char* command);

/* environment.c */
char* _getenv(const char* name);
char* which(char* filename, general_t* info);
void is_current_path(char* path, general_t* info);
void get_full_env(void);

/* execute.c */
void execute(char* commands, char** arguments, general_t* info, char* buff);
int current_directory(char* cmd, char** arguments, char* buff,
	general_t* info);

/* Entry point of the shell */
void start(general_t* info);

/* text.c */
void start_prompt(general_t* info);
void prompt(general_t* info);
char* read_prompt();
void sigintHandler(int sig_num);

/* printers.c */
int _putchar_to_fd(char l, int fd);
int print_to_fd(char* msg, int fd);

/* printers_out.c */
int _putchar(char c);
int print(char* msg);

/* printers_err.c */
int print_err(char* msg);

/* tokenization.c */
char** split_words(char* line, const char* sep);
char* join_words(char* word1, char* word2, char* word3, const char* sep);

/* patterns.c */
void analyze_patterns(general_t* info, char** arguments);
char* pattern_handler(general_t* info, char* string);
char* replace_value(general_t* info, int* index, char* string);

/* patterns_replacer.c */
char* replacement(general_t* info, int* index, char* string);
char* replace_env(general_t* info, char* environment);
#endif
