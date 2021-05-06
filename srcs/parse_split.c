/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 04:10:07 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/06 16:17:14 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int					ft_parse_split_count(char *lin)
{
	int				idx;
	int				cnt;
	int				flg;

	idx = 0;
	cnt = 0;
	flg = 1;
	while (lin[idx])
	{
		if (ft_util_is_empty(lin[idx]) == 0)
		{
			if (lin[idx] == '"')
			{
				++idx;
				while (lin[idx] && lin[idx] != '"')
					++idx;
			}
			else if (lin[idx] == '\'')
			{
				++idx;
				while (lin[idx] && lin[idx] != '\'')
					++idx;
			}
			else
				++idx;
		}
		else
		{
			if (flg == 1)
			{
				++cnt;
				flg = -1;
			}
			while (ft_util_is_empty(lin[idx]) == 1)
				++idx;
			flg = 1;
		}
	}
	return (cnt + 1);
}

char				*ft_parse_split_quotes(char *lin, int *jdx)
{
	char			*rst;
	int				flg;

	rst = ft_util_strdup("");
	flg = 0;
	while (lin[*jdx])
	{
		if (lin[*jdx] == '"' || lin[*jdx] == '\'')
		{
			if (lin[*jdx] == '"' && flg == 0)
				flg = 1;
			else if (lin[*jdx] == '\'' && flg == 0)
				flg = 1;
			else
				flg = 0;
			++(*jdx);
		}
		if (ft_util_is_empty(lin[*jdx]) == 1 && flg == 0)
			break ;
		else
			rst = ft_util_chajoin(rst, lin[*jdx]);
		++(*jdx);
	}
	return (rst);
}

char				**ft_parse_split_fail(char **rst, int num)
{
	int 			idx;

	idx = 0;
	while (idx < num)
	{
		free(rst[idx]);
		++idx;
	}
	free(rst);
	return (NULL);
}

char				**ft_parse_split(char *lin)
{
	int				cnt;
	char			**rst;
	int				idx;
	int				jdx;

	if (!lin)
		return (0);
	cnt = ft_parse_split_count(lin);
	if (!(rst = (char **)malloc(sizeof(char *) * (cnt + 1))))
		return (NULL);
	idx = 0;
	jdx = 0;
	while (idx < cnt)
	{
		while (ft_util_is_empty(lin[jdx]) == 1)
			++jdx;
		if (!(rst[idx] = ft_parse_split_quotes(lin, &jdx)))
			return (ft_parse_split_fail(rst, idx));
		++idx;
	}
	rst[idx] = NULL;
	return (rst);
}