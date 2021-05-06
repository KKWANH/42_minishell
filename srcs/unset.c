/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:47:19 by juhpark           #+#    #+#             */
/*   Updated: 2021/05/06 16:53:00 by kimkwanho        ###   ########.fr       */
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

int					ft_unset_check(char *cmd)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		if (ft_util_is_export(cmd[i]) == 0)
			return (0);
		i++;
	}
	return (1);
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
	if (ft_unset_check(par->spl[1]) == 0)
	{
		err_unset(par->spl[1]);
		return ;
	}
	if (g_mns->env == NULL)
		return ;
	ft_unset_delete_env(par->spl[1], &g_mns->env);
	g_mns->ext = 0;
}
