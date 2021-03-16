#ifndef MINISHELL_H
# define MINISHELL_H

/*
** includes
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <signal.h>
#include "libft/libft.h"


/*
** get_next_line.c
*/
int					get_next_line(int fd, char **line);

#endif