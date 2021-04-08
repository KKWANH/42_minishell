/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:28:28 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/08 17:12:56 by kimkwanho        ###   ########.fr       */
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
# include <term.h>
# include <termios.h>
# include <curses.h>
# include <termcap.h>

/*
** color codes
*/

# define ANSI_RED	"\x1b[31m"
# define ANSI_GRE	"\x1b[32m"
# define ANSI_YEL	"\x1b[33m"
# define ANSI_BLU	"\x1b[34m"
# define ANSI_MAG	"\x1b[35m"
# define ANSI_CYA	"\x1b[36m"
# define ANSI_RES	"\x1b[0m"

/*
** key codes
*/

# define BACKSPACE 127
# define LEFT_ARROW 4479771
# define RIGHT_ARROW 4414235
# define UP_ARROW 4283163
# define DOWN_ARROW 4348699

/*
** structs
*/

typedef struct		s_env
{
	char			*nam;
	char			*val;
	struct s_env	*nxt;
}					t_env;

typedef struct		s_cmd
{
	char			*lin;
	char			*cmd;
	char			*arg;
	struct s_cmd	*pre;
	struct s_cmd	*nxt;
}					t_cmd;

typedef struct		s_mns
{
	struct s_env	*env;
	char			**env_str;
	char			*pth;
	int				ext;
	char			*tmp;
	struct s_cmd	*cmd;
}					t_mns;

/*
** functions - gnl.c
*/
int					get_next_line(int fil, char **lin);

/*
** functions - signal.c
*/
void				ft_signal_set(void);

/*
** functions - env.c
*/
char				*ft_env_name(char *str);
char				*ft_env_value(char *str);
t_env				*ft_env_init(void);
void				ft_env_cmd(void);

/*
** functions - util_env.c
*/
t_env				*ft_util_env_lstnew(char *nam, char *val);
t_env				*ft_util_env_lstlast(t_env *lst);
void				ft_util_env_lstaddback(t_env **env, t_env *new);

/*
** functions - prompt.c
*/
void				ft_prompt_put_msg(void);

/*
** functions - parse.c
*/
int					ft_parse_cmd(char *lin);
void				ft_parse(char *lin);

/*
** functions - process.c
*/
int					ft_process(void);

/*
** functions - exit.c
*/
void				ft_exit_cmd(void);

/*
** functions - util1.c
*/
int					ft_util_strchr(const char *str, int chr);
int					ft_util_strlen(char *str);
void				ft_util_putstr_fd(char *str, int fil);
char				ft_util_ndlchk(const char *hay, const char *ndl, size_t len);
char				*ft_util_strnstr(const char *hay, const char *ndl, size_t len);

/*
** functions - util2.c
*/
char				*ft_util_strjoin(char const *s1, char const *s2);
char				*ft_util_strdup(char *src);
int					ft_util_is_empty(char c);
int					ft_util_is_alpha(int chr);
int					ft_util_strncmp(const char *s1, const char *s2,
					unsigned int n);

/*
** functions - util3.c
*/
int					ft_util_is_ascii(int chr);
char				**ft_util_split_ufailed(char **res, int num);
char				*ft_util_split_input(char *res, char *s, char c);
int 				ft_util_split_count(char *s, char c);
char				**ft_util_split(char const *s, char c);

/*
** functions - util4.c
*/
int					ft_util_is_export(char chr);
void				ft_util_freestrstr(char **str);
int					ft_util_strcmp(char *s1, char *s2);
t_cmd				*ft_util_cmd_lstlast(t_cmd *lst);
void				ft_util_cmd_lstaddback(t_cmd *cmd);

#endif