/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:57:42 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/03 17:38:30 by juhpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

void				err_by_exit_many(unsigned char *ext)
{
	ft_util_putstr_fd(ANSI_RED, 2);
	ft_util_putstr_fd("minishell: exit: too many arguments\n", 2);
	ft_util_putstr_fd(ANSI_RES, 2);
	*ext = 1;
}

void				ft_exit_check(t_par *par)
{
	int ext;

	ext = 0;
	while (par->spl[1][ext])
	{
		if (!(ft_util_is_num(par->spl[1][ext])))
		{
			err_by_exit(par->spl[1], &g_mns->ext);
			break ;
		}
		ext++;
	}
	if (g_mns->ext != ext)
	{
		ext = ft_util_atoi(par->spl[1]);
		g_mns->ext = ext;
	}
}

void				ft_exit_cmd(t_par *par)
{
	if (ft_util_strlen(par->spl[1]) != 0)
		ft_exit_check(par);
	if (par->pip == 1)
		return ;
	printf("exit\n");
	if (par->spl[1] && par->spl[2])
	{
		err_by_exit_many(&g_mns->ext);
		return ;
	}
	if (g_mns->ext != 0)
		exit(g_mns->ext);
	else
		exit(0);
}
