/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 09:32:16 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/06 08:37:21 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

t_cap				ft_init_term_set
	(t_cap cap, struct termios *s_term, struct termios *s_backup)
{
	tcgetattr(STDIN_FILENO, s_term);
	tcgetattr(STDIN_FILENO, s_backup);
	s_term->c_lflag &= ~(ECHO | ICANON);
	s_term->c_cc[VMIN] = 1;
	s_term->c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, s_term);
	tgetent(NULL, getenv("TERM"));
	cap.cm = tgetstr("cm", NULL);
	cap.ce = tgetstr("ce", NULL);
	cap.dc = tgetstr("dc", NULL);
	return (cap);
}

void				ft_init
	(char **str, struct termios *s_term, struct termios *s_backup)
{
	ft_signal_set();
	g_mns->env_str = str;
	g_mns->env = NULL;
	ft_env_init();
	g_mns->pth = 0;
	g_mns->ext = 0;
	g_mns->tmp = NULL;
	g_mns->idx = -1;
	g_mns->cmd = NULL;
	g_mns->cap = ft_init_term_set(g_mns->cap, s_term, s_backup);
	g_mns->fst = 0;
	ft_prompt_intro();
}
