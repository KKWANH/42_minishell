/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:42:08 by pjh399            #+#    #+#             */
/*   Updated: 2021/05/06 06:43:13 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int					ft_util_cal(char *a, int res, int minus)
{
	int				i;

	i = 0;
	while (a[i] >= '0' && a[i] <= '9')
	{
		res = ((res * 10) + (a[i] - 48));
		i++;
		if (((res == 214748364 && a[i] >= '8') ||
					(res > 214748364 && a[i] > '0')) && minus == 0)
			return (-1);
		if (((res == 214748364 && a[i] >= '9') ||
					(res > 214748364 && a[i] > '0')) && minus == 1)
			return (0);
	}
	if (minus == 1)
		res *= -1;
	return (res);
}

int					ft_util_atoi(char *str)
{
	int				i;
	char			*a;
	int				res;

	i = 0;
	res = 0;
	while ((*str == '\t') || (*str == '\n') || (*str == '\v')
		|| (*str == '\f') || (*str == '\r') || (*str == ' '))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i++;
		str++;
	}
	if (*str < '0' || *str > '9')
		return (0);
	a = str;
	return (ft_util_cal(a, res, i));
}

char				**ft_util_strstrjoin(char **spl, char *str)
{
	char			**rst;
	int				cnt;
	int				idx;

	if (!spl || !str)
		return (NULL);
	cnt = 0;
	while (spl[cnt])
		++cnt;
	rst = (char **)malloc(sizeof(char *) * (cnt + 1));
	idx = 0;
	while (idx < cnt)
	{
		rst[idx] = spl[idx];
		++idx;
	}
	rst[idx] = str;
	ft_util_freestrstr(spl);
	return (rst);
}