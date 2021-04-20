/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 09:05:10 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/19 10:53:49 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

int					ft_util_is_export(char chr)
{
	if ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z') ||
		chr == '_' || chr == '/' || chr == '\\')
		return (1);
	return (0);
}

int					ft_util_strcmp(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (-1);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[j])
			break ;
		i++;
		j++;
	}
	return (s1[i] - s2[i]);
}

void				ft_util_freestrstr(char **str)
{
	int				idx;

	idx = 0;
	while (str[idx])
		free(str[idx++]);
	free(str);
}

t_cmd				*ft_util_cmd_lstlast(t_cmd *lst)
{
	if (!lst)
		return (NULL);
	while (lst->nxt)
		lst = lst->nxt;
	return (lst);
}

void				ft_util_cmd_lstaddback(t_cmd *cmd)
{
	t_cmd			*tmp;

	tmp = ft_util_cmd_lstlast(g_mns->cmd);
	if (!(g_mns->cmd))
		g_mns->cmd = cmd;
	else
	{
		(ft_util_cmd_lstlast(g_mns->cmd))->nxt = cmd;
		(ft_util_cmd_lstlast(g_mns->cmd))->pre = tmp;
	}
}
