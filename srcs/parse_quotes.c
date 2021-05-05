/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:43:14 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/06 06:30:27 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char				*ft_parse_quotes_process
	(char **spl, int *idx, int *jdx, char *str)
{
	int				num;
	int				cnt;
	char			*rst;
	char			*rrst;

	num = 0;
	cnt = 0;
	// if (ft_parse_quotes_is_close(spl, idx, *jdx) == -1)
	// {
	// 	(*jdx) += 1;
	// 	return (str);
	// }
	while (spl[*idx][(*jdx) + 1 + cnt] && spl[*idx][(*jdx) + 1 + cnt] != '\"')
		++cnt;
	rst = (char *)malloc(sizeof(char) * (cnt + 1));
	while (num < cnt)
	{
		rst[num] = spl[*idx][(*jdx) + 1 + num];
		++num;
	}
	rst[num] = 0;
	(*jdx) += cnt + 1;
	rrst = ft_util_strjoin(str, rst);
	free(rst);
	rst = 0;
	return (rrst);
}

int					ft_parse_quotes(int *idx, char **spl)
{
	int				jdx;
	char			*rst;

	jdx = 0;
	rst = ft_util_strdup("");
	while (spl[*idx][jdx])
	{
		if (spl[*idx][jdx] == '\"')
			rst = ft_parse_quotes_process(spl, idx, &jdx, rst);
		else
		{
			rst = ft_util_chajoin(rst, spl[*idx][jdx]);
			++jdx;
		}
	}
	free(spl[*idx]);
	spl[*idx] = 0;
	spl[*idx] = rst;
	return (0);
}
