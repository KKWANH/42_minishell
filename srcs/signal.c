/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:02:14 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/03/31 10:01:27 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

void				ft_signal_handle_c(int sig)
{
	int				sta;
	int				pid;

	pid = waitpid(0, &sta, WNOHANG);
	if (sig == 2)
	{
		if (pid == -1)
		{
			ft_util_putstr_fd("\b\b \b\b\n", 1);
			ft_prompt_put_msg();
			g_mns->exit_code = 1;
		}
		else
		{
			ft_util_putstr_fd("\n", 1);
			g_mns->exit_code = 130;
		}
	}
}

void				ft_signal_handle_rvc_slash(int sig)
{
	int				sta;
	int				pid;

	pid = waitpid(0, &sta, WNOHANG);
	if (pid == -1)
		ft_util_putstr_fd("\b\b \b\b\n", 1);
	else
	{
		signal(sig, SIG_DFL);
		ft_util_putstr_fd("Quit: 3\n", 1);
		g_mns->exit_code = 131;
		signal(3, ft_signal_handle_rvc_slash);
	}
}

void				ft_signal_set(void)
{
	signal(2, ft_signal_handle_c);
	signal(15, ft_signal_handle_rvc_slash);
}