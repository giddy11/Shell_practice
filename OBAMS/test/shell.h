#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>

char **split_str(char *str, const char *delim);
void run_cmd(char **argv);
char *get_path(char *cmd);
#endif /*_SHELL_H*/
