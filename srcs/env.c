/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:38:17 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/04 16:46:19 by juhpark          ###   ########.fr       */
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
	if (!(rst = (char *)malloc(sizeof(char) * eqr + 1)))
		return (NULL);
	while (idx < eqr)
	{
		rst[idx] = str[idx];
		++idx;
	}
	rst[idx] = '\0';
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
	if (!(rst = (char *)malloc(sizeof(char) * (len - eqr + 1))))
		return (NULL);
	while ((idx + eqr + 1) <= len)
	{
		rst[idx] = str[idx + eqr + 1];
		++idx;
	}
	rst[idx] = '\0';
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
		new = ft_util_env_lstnew(ft_env_name(g_mns->env_str[idx]),
				ft_env_value(g_mns->env_str[idx]));
		ft_util_env_lstaddback(&rst, new);
		++idx;
	}
	return (rst);
}

void				ft_env_cmd(char **inp)
{
	t_env			*tmp;

	tmp = g_mns->env;
	if (!inp)
		inp = 0;
	while (tmp)
	{
		ft_util_putstr_fd(tmp->nam, 1);
		ft_util_putstr_fd(" = ", 1);
		ft_util_putstr_fd(tmp->val, 1);
		ft_util_putstr_fd("\n", 1);
		tmp = tmp->nxt;
	}
}
