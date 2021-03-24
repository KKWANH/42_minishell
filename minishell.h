/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:51:45 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/03/24 08:28:04 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** includes
*/
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/resource.h>
# include <sys/stat.h>
# include <signal.h>

# define ANSI_RED	"\x1b[31m"
# define ANSI_GRE	"\x1b[32m"
# define ANSI_YEL	"\x1b[33m"
# define ANSI_BLU	"\x1b[34m"
# define ANSI_MAG	"\x1b[35m"
# define ANSI_CYA	"\x1b[36m"
# define ANSI_RES	"\x1b[0m"


typedef struct		s_env
{
	char			*nam;
	char			*val;
	struct s_env	*nxt;
}					t_env;

typedef struct		s_mns
{
	int				ctr;
	char			*pth;
	t_env			*env;
}					t_mns;

/*
** get_next_line.c
*/
int					get_next_line(int file, char **line);

/*
** env.c
*/
char				*ft_env_name(char *str);
char				*ft_env_value(char *str);
t_env				*ft_env_init(char **env);

/*
** util_env1.c
*/
t_env				*ft_util_env_lstnew(char *nam, char *val);
t_env				*ft_util_env_lstlast(t_env *lst);
void				ft_util_env_lstaddback(t_env **env, t_env *new);

/*
** signal.c
*/
void				ft_signal_handle(int sig);
void				ft_signal_set(void);

/*
** prompt.c
*/
void				ft_prompt_put_msg(void);

/*
** util1.c
*/
int					ft_util_strchr(const char *str, int chr);
int					ft_util_strlen(char *str);
void				ft_util_putstr_fd(char *str, int fil);
char				ft_util_ndlchk(const char *hay, const char *ndl, size_t len);
char				*ft_util_strnstr(const char *hay, const char *ndl, size_t len);

/*
** util2.c
*/
char				*ft_util_strjoin(char const *s1, char const *s2);
char				*ft_util_strdup(char *src);

#endif