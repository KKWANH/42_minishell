/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:51:45 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/05 09:18:57 by kimkwanho        ###   ########.fr       */
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

typedef struct		s_cmd
{
	char			*lin;
	char			*cmd;
	int				stt;
	int				is_finish;
	struct s_cmd	*nxt;
}					t_cmd;

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
	char			*tmp_char;
	int				exit_code;
	t_env			*env;
	char			**env_str;
	t_cmd			*cmd;
}					t_mns;

/*
** gnl.c
*/
int					get_next_line(int file, char **line);

/*
** env.c
*/
char				*ft_env_name(char *str);
char				*ft_env_value(char *str);
t_env				*ft_env_init(void);
void				ft_env_cmd(void);

/*
** util_env1.c
*/
t_env				*ft_util_env_lstnew(char *nam, char *val);
t_env				*ft_util_env_lstlast(t_env *lst);
void				ft_util_env_lstaddback(t_env **env, t_env *new);

/*
** signal.c
*/
void				ft_signal_handle_c(int sig);
void				ft_signal_handle_rvc_slash(int sig);
void				ft_signal_set(void);

/*
** prompt.c
*/
void				ft_prompt_put_msg(void);

/*
** parse.c
*/
void				ft_parse(char *lin);

/*
** process.c
*/
int					ft_process();

/*
** exit.c
*/
void				ft_exit_cmd(void);

/*
** export.c
*/
int					ft_export_cmd(char *lin);

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
int					ft_util_is_empty(char c);
int					ft_util_is_alpha(int chr);
int					ft_util_strncmp(const char *s1, const char *s2,
					unsigned int n);

/*
** util3.c
*/
int					ft_util_is_ascii(int chr);
char				**ft_util_split_ufailed(char **res, int num);
char				*ft_util_split_input(char *res, char *s, char c);
int 				ft_util_split_count(char *s, char c);
char				**ft_util_split(char const *s, char c);

/*
** util4.c
*/
int					ft_util_is_export(char chr);
void				ft_util_freestrstr(char **str);
int					ft_util_strcmp(char *s1, char *s2);
t_cmd				*ft_util_cmd_lstlast(t_cmd *lst);
void				ft_util_cmd_lstaddback(t_cmd *cmd);

#endif