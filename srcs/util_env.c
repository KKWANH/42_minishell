/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:59:51 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/05 21:43:15 by juhpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_mns				*g_mns;

t_env				*ft_util_env_lstnew(char *nam, char *val)
{
	t_env			*new;

	if (!(new = malloc(sizeof(t_env))))
		return (NULL);
	new->nam = nam;
	new->val = val;
	new->nxt = 0;
	return (new);
}

t_env				*ft_util_env_lstlast(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->nxt)
		lst = lst->nxt;
	return (lst);
}

void				ft_util_env_lstaddback(t_env **env, t_env *new)
{
	if (!env || !new)
		return ;
	if (!(*env))
		*env = new;
	else
		(ft_util_env_lstlast(*env))->nxt = new;
}

char				*ft_util_env_search(char *cmd)
{
	t_env			*tmp;

	tmp = g_mns->env;
	while (tmp)
	{
		if (ft_util_strcmp(tmp->nam, cmd) == 0)
		{
			if (tmp->val)
				return (tmp->val);
		}
		tmp = tmp->nxt;
	}
	return (0);
}
