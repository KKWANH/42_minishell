/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:42:52 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/03/27 22:47:35 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

char				*ft_env_name(char *str)
{
	char			*rst;
	int				eqr;
	int				idx;

	eqr = ft_util_strchr(str, '=');
	idx = 0;
	if (!(rst = (char *)malloc(sizeof(char) * eqr)))
		return (NULL);
	while (idx < eqr)
	{
		rst[idx] = str[idx];
		++idx;
	}
	return (rst);
}

char				*ft_env_value(char *str)
{
	char			*rst;
	int				eqr;
	int				len;
	int				idx;

	eqr = ft_util_strchr(str, '=');
	len = ft_util_strlen(str);
	idx = 0;
	if (!(rst = (char *)malloc(sizeof(char) * (len - eqr))))
		return (NULL);
	while ((idx + eqr + 1) <= len)
	{
		rst[idx] = str[idx + eqr + 1];
		++idx;
	}
	return (rst);
}

t_env				*ft_env_init(void)
{
	t_env			*rst;
	t_env			*new;
	int				idx;

	rst = ft_util_env_lstnew(
		ft_env_name(g_mns->env_str[0]), ft_env_value(g_mns->env_str[0]));
	idx = 1;
	while (g_mns->env_str[idx])
	{
		new = ft_util_env_lstnew(
			ft_env_name(g_mns->env_str[idx]), ft_env_value(g_mns->env_str[idx]));
		ft_util_env_lstaddback(&rst, new);
		++idx;
	}
	return (rst);
}

void				ft_env_cmd(void)
{
	t_env			*tmp;

	tmp = g_mns->env;
	while (tmp)
	{
		printf("%s = %s\n", tmp->nam, tmp->val);
		tmp = tmp->nxt;
	}
}
