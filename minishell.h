/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:28:28 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/07 17:45:32 by kimkwanho        ###   ########.fr       */
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
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/resource.h>
# include <sys/stat.h>
# include <signal.h>
# include <term.h>
# include <termios.h>
# include <curses.h>
# include <termcap.h>
# include <errno.h>
# include <string.h>

/*
** color codes
*/

# define ANSI_RES	"\x1b[0m"
# define ANSI_BOL	"\x1b[1m"
# define ANSI_ITA	"\x1b[3m"
# define ANSI_RED	"\x1b[31m"
# define ANSI_GRE	"\x1b[32m"
# define ANSI_YEL	"\x1b[33m"
# define ANSI_BLU	"\x1b[34m"
# define ANSI_MAG	"\x1b[35m"
# define ANSI_CYA	"\x1b[36m"

/*
** key codes
*/

# define CTRL_D 4
# define ENTER 10
# define BACKSPACE 127
# define LEFT_ARROW 4479771
# define RIGHT_ARROW 4414235
# define UP_ARROW 4283163
# define DOWN_ARROW 4348699
# define TYPE_NO 0
# define TYPE_PIPE 1
# define TYPE_SEMI 2
# define CLOSE 0
# define SINGLE 1
# define DOUBLE 2

/*
** structs
*/

typedef struct		s_quo
{
	int				type;
	int				d_open;
	int				s_open;
	int				j;
	int				e;
	char			*n;
	char			*v;
}					t_quo;

typedef struct		s_env
{
	char			*nam;
	char			*val;
	struct s_env	*nxt;
}					t_env;

typedef struct		s_par
{
	char			**spl;
	int				fil[2];
	int				typ;
	int				pip;
	int				fd_in;
	int				fd_out;
	struct s_par	*nxt;
	struct s_par	*pre;
}					t_par;

typedef struct		s_cmd
{
	char			*lin;
	int				cur;
	struct s_cmd	*pre;
	struct s_cmd	*nxt;
}					t_cmd;

typedef struct		s_cap
{
	char			*cm;
	char			*ce;
	char			*dc;
	int				p_row;
	int				p_col;
}					t_cap;

typedef struct		s_mns
{
	struct s_env	*env;
	char			**env_str;
	char			*pth;
	int				ext;
	char			*tmp;
	int				idx;
	char			*lin;
	int				test;
	int				fst;
	struct s_cmd	*cmd;
	struct s_cap	cap;
}					t_mns;

/*
**	[init.c]
*/
void				ft_init
	(char **str, struct termios *s_term, struct termios *s_backup);

/*
**	[signal.c]
*/
void				ft_signal_set(void);

/*
**	[prompt.c]
*/
void				ft_prompt_put_msg(void);
void				ft_prompt_intro(void);

/*
**	[cursor.c]
*/
void				ft_cursor_whereisit(int *col, int *row);
int					ft_cursor(int *col, int *row, int tmp);

/*
**	[key.c]
*/
char				*ft_key_back(int *col, int *row, char *lin, t_cap *cap);
void				ft_key_left(int *col, int *row, t_cap *cap);
void				ft_key_right(int *col, int *row, char *lin, t_cap *cap);
void				ft_key_up(int *col, int *row, char **lin, t_cap *cap);
void				ft_key_down(int *col, int *row, char **lin, t_cap *cap);

/*
**	[history.c]
*/
char				*ft_history_up(void);
char				*ft_history_down(void);
void				ft_history_set_zero(void);

/*
**	[exe.c]
*/
void				ft_exe(char *lin);

/*
**	[util_exe.c]
*/
void				ft_util_dup_fd(t_par *par);
char				**ft_util_parse_path(void);
int					ft_util_is_execable(char *path);
void				ft_util_open_pipe(t_par *par);
void				ft_util_close_pipe(t_par *par);

/*
**	[parse.c]
*/
t_par				*ft_parse_cmd(char *lin, t_par *par);

/*
**	[parse2.c]
*/
void				ft_parse_quotes_big_sub(char **spl, int *i, char *rst);
void				ft_parse_quotes_sml_sub(char **spl, int *i, char *rst);
void				ft_parse_split_count_sub_blank(char *lin, int *idx);
int					ft_parse_process_special_quotes(char **spl, int *idx);
/*
**	[parse_space.c]
*/
void				ft_quo_init(t_quo *quo);
char				*ft_parse_space(char *lin, int i);
char				*ft_input_lin(char *lin, char *ret, int i, int j);
void				err_by_syntax(int *ext);

/*
**	[parse_space_tocken.c]
*/
char				*ft_parse_sp_op(char *lin, char *ret, int *i, t_quo *quo);
int					token_semi(char *lin, int ret, int indx);
int					token_pipe(char *lin, int ret, int indx);
int					token_decresc(char *lin, int ret, int indx);
int					token_cresc(char *lin, int ret, int indx);

/*
**	[parse_split.c]
*/
char				**ft_parse_split(char *lin);

/*
**	[parse_dollar.c]
*/
int					ft_parse_dollar(int *idx, char **spl);

/*
**	[util_parse.c]
*/
int					ft_util_parse_list_rewind(t_par **par);
int					ft_util_parse_list_free(t_par **par);
t_par				*ft_util_parse_init(void);

/*
**	[redir.c]
*/
void				ft_redir_check(t_par *par);

/*
**	[builtin.c]
*/
int					ft_builtin_check(char *cmd);
int					ft_builtin(t_par *par);

/*
**	[pwd.c]
*/
void				ft_pwd_cmd(t_par *par);

/*
**	[exit.c]
*/
void				ft_exit_cmd(t_par *par);

/*
**	[cd.c]
*/
void				ft_cd_cmd(t_par *par);

/*
**	[echo.c]
*/
void				ft_echo_cmd(t_par *par);

/*
**	[env.c]
*/
void				ft_env_add_update(char *nam, char *val);
void				ft_env_init(void);
void				ft_env_cmd(char **inp);

/*
**	[util_env.c]
*/
t_env				*ft_util_env_lstnew(char *nam, char *val);
t_env				*ft_util_env_lstlast(t_env *lst);
void				ft_util_env_lstaddback(t_env *new);
char				*ft_util_env_search(char *cmd);

/*
**	[export.c]
*/
void				ft_export_cmd(t_par *par);

/*
**	[unset.c]
*/
void				ft_unset_cmd(t_par *par);

/*
**	[err.c]
*/
void				err_by_exit(char *arg, int *ext);
void				err_by_chdir(char *arg, int *ext);
void				err_by_command(char *par, int *ext);
void				err_by_path(char *par, int *ext);
void				err_by(char *msg, int *ext);

/*
**	[util1.c]
*/
int					ft_util_strchr(const char *str, int chr);
int					ft_util_strlen(char *str);
void				ft_util_putstr_fd(char *str, int fil);
char				ft_util_ndlchk(const char *hay, const char *ndl, size_t l);
char				*ft_util_strnstr(const char *hay, const char *nd, size_t l);

/*
**	[util2.c]
*/
char				*ft_util_strjoin(char const *s1, char const *s2);
char				*ft_util_strdup(char *src);
int					ft_util_is_empty(char c);
int					ft_util_is_alpha(int chr);
int					ft_util_strncmp(const char *s1, const char *s2,
					unsigned int n);

/*
**	[util3.c]
*/
int					ft_util_is_ascii(int chr);
char				**ft_util_split_ufailed(char **res, int num);
char				*ft_util_split_input(char *res, char *s, char c);
int					ft_util_split_count(char *s, char c);
char				**ft_util_split(char const *s, char c);

/*
**	[util4.c]
*/
int					ft_util_is_export(char chr);
void				ft_util_freestrstr(char **str);
int					ft_util_strcmp(char *s1, char *s2);
t_cmd				*ft_util_cmd_lstlast(t_cmd *lst);
void				ft_util_cmd_lstaddback(t_cmd *cmd);

/*
**	[util5.c]
*/
char				*ft_util_chajoin(char *line, char c);
int					ft_util_putchar(int tc);
char				*ft_util_addcha(char *line, char c, int indx);
char				*ft_util_chaout(char *line, int indx);
int					ft_util_is_num(char chr);

/*
**	[util6.c]
*/
int					ft_util_cal(char *a, int res, int minus);
int					ft_util_atoi(char *str);
char				**ft_util_strstrjoin(char **spl, char *str);
size_t				ft_util_itoa_num_length(int nbr);
char				*ft_util_itoa(int n);

#endif
