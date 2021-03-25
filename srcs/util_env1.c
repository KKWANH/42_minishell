/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_env1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:59:51 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/03/25 13:22:19 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
