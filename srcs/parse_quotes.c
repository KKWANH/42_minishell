/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:43:14 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/06 02:47:26 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int					ft_parse_quotes(int *idx, char **spl)
{
	int				stt;
	int				end;
	int				nm1; // : spl
	int				nm2; // : rst
	char			*rst;

	stt = 0;
	while (spl[*idx][stt] && spl[*idx][stt] != '\"')
		++stt;
	end = stt + 1;
	while (spl[*idx][end] && spl[*idx][end] != '\"')
		++end;
	rst = (char *)malloc(sizeof(char) * (end - stt + 1));
	nm1 = 0;
	nm2 = 0;
	while (nm1 < stt)
	{
		rst[nm2] = spl[*idx][nm1];
		++nm2;
		++nm1;
	}
	++nm1;
	while (nm1 < end)
	{
		rst[nm2] = spl[*idx][nm1];
		++nm2;
		++nm1;
	}
	rst[nm2] = '\0';
	free(spl[*idx]);
	spl[*idx] = 0;
	spl[*idx] = rst;
	return (0);
}
