/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 09:32:16 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/09 09:38:15 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

void				ft_init_term_set(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHO | ICANON);
//	term.c_lflag &= ~(ISIG);
//	term.c_lflag &= ~ECHO;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
//	term.c_cc[VEOF] = 4;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
//	tgetent(NULL, getenv("TERM"));
}

void				ft_init(char **str)
{
	ft_signal_set();
	g_mns->env_str = str;
	g_mns->env = ft_env_init();
	g_mns->pth = 0;
	g_mns->ext = 0;
	g_mns->tmp = NULL;
	ft_init_term_set();
	ft_prompt_put_msg();
}
