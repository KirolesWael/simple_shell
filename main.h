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

/*buffer.c*/
char *create_buff();

void start(main_t *inf);

#endif
