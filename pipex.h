
#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*join_path(char *path, char *cmd);
char	*find_path(char *cmd, char *envp[]);
#endif


