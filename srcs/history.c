/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 14:48:44 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/03 23:58:32 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

/*
lin		cur		1up
ls		0		0
pwd		0		0
env		0		0
asd		0		0
sdf		0		1

try up
 0 0 0 0 1, sdf
try up
 0 0 0 1 0, asd
*/

char				*ft_history_down(void)
{
	t_cmd			*tmp;

	if (g_mns->fst == 0)
		return (NULL);
	tmp = g_mns->cmd;
	while (tmp)
	{
		if (tmp->cur == 1)
		{
			if (tmp->nxt)
			{
				tmp->cur = 0;
				tmp = tmp->nxt;
			}
			tmp->cur = 1;
			return (tmp->lin);
		}
		else if (!tmp->nxt)
			break ;
		tmp = tmp->nxt;
	}
	return (NULL);
}

char				*ft_history_up(void)
{
	t_cmd			*tmp;

	if (g_mns->fst == 0)
		return (NULL);
	tmp = ft_util_cmd_lstlast(g_mns->cmd);
	while (tmp)
	{
		if (tmp->cur == 1)
		{
			if (tmp->pre)
			{
				tmp->cur = 0;
				tmp = tmp->pre;
			}
			tmp->cur = 1;
			return (tmp->lin);
		}
		else if (!tmp->pre)
			break ;
		tmp = tmp->pre;
	}
	ft_util_cmd_lstlast(g_mns->cmd)->cur = 1;
	return (ft_util_cmd_lstlast(g_mns->cmd)->lin);
}

void				ft_history_set_zero(void)
{
	t_cmd			*tmp;

	tmp = g_mns->cmd;
	g_mns->fst = 1;
	while (tmp)
	{
		tmp->cur = 0;
		if (tmp->nxt)
			tmp = tmp->nxt;
		else
			break ;
	}
	return ;
}