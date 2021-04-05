/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:35:02 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/05 09:23:11 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

int					ft_export_getname_eqr(char *lin, int *mlc, int *stt)
{
	int				idx;

	idx = 0;
	while (ft_util_is_empty(lin[idx]))
		++idx;
	if ((lin[idx] == 'E' && lin[idx + 1] == 'X' && lin[idx + 2] == 'P' &&
		lin[idx + 3] == 'O' && lin[idx + 4] == 'R' && lin[idx + 5] == 'T') ||
		(lin[idx] == 'e' && lin[idx + 1] == 'x' && lin[idx + 2] == 'p' &&
		lin[idx + 3] == 'o' && lin[idx + 4] == 'r' && lin[idx + 5] == 't'))
		idx += 6;
	while (ft_util_is_empty(lin[idx]))
		++idx;
	(*stt) = idx;
	while (ft_util_is_alpha(lin[idx]) || lin[idx] == '_')
	{
		++idx;
		++(*mlc);
	}
	if (lin[idx] == '=')
		return (1);
	return (0);
}

char				*ft_export_getname(char *lin)
{
	char			*rst;
	int				stt;
	int				mlc;
	int				idx;

	mlc = 0;
	stt = 0;
	idx = 0;
	if (ft_export_getname_eqr(lin, &mlc, &stt) == 0)
		return (NULL);
	if (!(rst = (char *)malloc(sizeof(char) * mlc)))
		return (NULL);
	while (idx < mlc)
		rst[idx++] = lin[stt++];
	return (rst);
}

int					ft_export_getvalue_eqr(char *lin, int *mlc, int *stt)
{
	int				idx;

	idx = 0;
	while (ft_util_is_empty(lin[idx]))
		++idx;
	if ((lin[idx] == 'E' && lin[idx + 1] == 'X' && lin[idx + 2] == 'P' &&
		lin[idx + 3] == 'O' && lin[idx + 4] == 'R' && lin[idx + 5] == 'T') ||
		(lin[idx] == 'e' && lin[idx + 1] == 'x' && lin[idx + 2] == 'p' &&
		lin[idx + 3] == 'o' && lin[idx + 4] == 'r' && lin[idx + 5] == 't'))
		idx += 6;
	while (ft_util_is_empty(lin[idx]) || ft_util_is_export(lin[idx]))
		++idx;
	if (lin[idx] != '=' || ft_util_is_empty(lin[idx + 1]))
		return (0);
	++idx;
	if (lin[idx] == '\"')
		++idx;
	(*stt) = idx;
	while (ft_util_is_alpha(lin[idx]))
	{
		++idx;
		++(*mlc);
	}
	return (1);
}

char				*ft_export_getvalue(char *lin)
{
	char			*rst;
	int				stt;
	int				mlc;
	int				idx;

	mlc = 0;
	stt = 0;
	idx = 0;
	if (ft_export_getvalue_eqr(lin, &mlc, &stt) == 0)
		return (NULL);
	if (!(rst = (char *)malloc(sizeof(char) * mlc)))
		return (NULL);
	while (idx < mlc)
		rst[idx++] = lin[stt++];
	return (rst);
}

int					ft_export_cmd(char *lin)
{
	char			*nam;
	char			*val;
	t_env			*new;
	t_env			*tmp;

	if (!(nam = ft_export_getname(lin)))
		return (0);
	if (!(val = ft_export_getvalue(lin)))
		return (0);
	new = ft_util_env_lstnew(nam, val);
	tmp = g_mns->env;
	while (tmp)
	{
		if (ft_util_strncmp(tmp->nam, new->nam, ft_util_strlen(new->nam)) == 0)
		{
			tmp->val = new->val;
			return (1);
		}
		if (tmp->nxt)
			tmp = tmp->nxt;
		else
		{
			ft_util_env_lstaddback(&tmp, new);
			return (1);
		}
	}
	return (1);
}