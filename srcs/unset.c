/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:47:19 by juhpark           #+#    #+#             */
/*   Updated: 2021/05/07 01:35:25 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_mns				*g_mns;

void				err_unset(char *cmd)
{
	ft_util_putstr_fd(ANSI_RED "minishell: ", 2);
	ft_util_putstr_fd(ANSI_MAG "unset: '", 2);
	ft_util_putstr_fd(ANSI_YEL, 2);
	ft_util_putstr_fd(cmd, 2);
	ft_util_putstr_fd(ANSI_MAG "': not a valid indentifier\n", 2);
	ft_util_putstr_fd(ANSI_RES, 2);
	g_mns->ext = 1;
}

void				ft_delete_env(t_env *del)
{
	free(del->nam);
	free(del->val);
	free(del);
}

void				ft_unset_delete_env(char *cmd, t_env **head)
{
	t_env			*tmp;
	t_env			*prv;

	tmp = *head;
	if (ft_util_strcmp(tmp->nam, cmd) == 0)
	{
		*head = tmp->nxt;
		ft_delete_env(tmp);
		return ;
	}
	while (tmp)
	{
		if (ft_util_strcmp(tmp->nam, cmd) == 0)
		{
			prv->nxt = tmp->nxt;
			ft_delete_env(tmp);
			return ;
		}
		prv = tmp;
		tmp = tmp->nxt;
	}
}

void				ft_unset_cmd(t_par *par)
{
	int				idx;
	int				jdx;

	idx = 0;
	while (par->spl[idx])
	{
		jdx = 0;
		while (par->spl[idx][jdx])
		{
			if ((ft_util_is_num(par->spl[idx][jdx]) == 0 &&
				ft_util_is_alpha(par->spl[idx][jdx]) == 0) ||
				(jdx == 0 && ft_util_is_num(par->spl[idx][jdx]) == 1))
			{
				err_unset(par->spl[idx]);
				break ;
			}
			++jdx;
		}
		ft_unset_delete_env(par->spl[idx], &g_mns->env);
		g_mns->ext = 0;
		++idx;
	}
}
