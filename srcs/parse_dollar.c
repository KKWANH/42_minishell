/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:43:14 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/07 18:30:12 by juhpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

char				*ft_parse_dollar_process(char *lin, int *jdx, char *str)
{
	int				cnt;
	int				ndx;
	char			*nam;
	char			*val;
	char			*rst;

	cnt = 0;
	while (lin[(*jdx) + 1 + cnt] && ft_util_is_alpha(lin[(*jdx) + 1 + cnt]))
		++cnt;
	if (cnt == 0)
		return (str);
	nam = (char *)malloc(sizeof(char) * (cnt + 1));
	ndx = 0;
	while (ndx < cnt)
	{
		nam[ndx] = lin[(*jdx) + 1 + ndx];
		++ndx;
	}
	nam[ndx] = 0;
	(*jdx) += (cnt + 1);
	val = ft_util_env_search(nam);
	if (!val)
		return (str);
	rst = ft_util_strjoin(str, val);
	return (rst);
}

int					ft_parse_dollar_error
	(char **spl, int *idx, int *jdx, char **rst)
{
	char			*tmp;
	char			*tm2;

	tmp = (*rst);
	if (spl[*idx][(*jdx) + 1] == '?')
	{
		tm2 = ft_util_itoa(g_mns->ext);
		(*rst) = ft_util_strjoin(tmp, tm2);
		(*jdx) += 2;
		free(tm2);
		return (-1);
	}
	if (ft_util_is_alpha(spl[*idx][(*jdx) + 1]) == 0)
	{
		spl[*idx][(*jdx)] = ' ';
		(*jdx) += 1;
		return (1);
	}
	return (1);
}

int					ft_parse_dollar(int *idx, char **spl)
{
	int				jdx;
	char			*rst;

	jdx = 0;
	rst = ft_util_strdup("");
	while (spl[*idx][jdx])
	{
		if (spl[*idx][jdx] == '$')
		{
			if (ft_parse_dollar_error(spl, idx, &jdx, &rst) == -1)
				continue ;
			rst = ft_parse_dollar_process(spl[*idx], &jdx, rst);
		}
		else
			rst = ft_util_chajoin(rst, spl[*idx][jdx++]);
	}
	free(spl[*idx]);
	spl[*idx] = 0;
	spl[*idx] = rst;
	return (0);
}
