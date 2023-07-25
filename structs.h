#ifndef STRUCTS_C
#define STRUCTS_C
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
    void (*exec)(main_t *info, char **argunemt)
} builtinfunc_t;

#endif