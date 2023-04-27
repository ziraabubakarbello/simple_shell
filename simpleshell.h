#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int execute(char **argv);
int stat(const char *pathname, struct stat *statbuf);
char *getPath(char *shell_command);
char *getenv(const char *name);
int shell_launch(char **argv);
#endif
