/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:13:55 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/03 17:31:24 by juhpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_mns				*g_mns;

void				ft_cd_cmd(t_par *par)
{
	char			*hom;

	if (par->spl[1] == NULL)
	{
		hom = getenv("HOME");
		if (chdir(hom) == -1)
		{
			ft_util_putstr_fd(ANSI_RED, 2);
			ft_util_putstr_fd("bash : cd: HOME not set\n", 2);
			ft_util_putstr_fd(ANSI_RES, 2);
			return ;
		}
	}
	else if (chdir(par->spl[1]) == -1)
		err_by_chdir(par->spl[1], &g_mns->ext);
	g_mns->ext = 0;
}
