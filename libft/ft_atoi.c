/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:35:13 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/10/03 18:04:14 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int					sgn;
	unsigned long int	rst;
	size_t				idx;

	idx = 0;
	sgn = 1;
	rst = 0;
	while (str[idx] == '\t' || str[idx] == '\n' || str[idx] == '\v' ||
			str[idx] == '\f' || str[idx] == '\r' || str[idx] == ' ')
		++idx;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sgn *= -1;
		++idx;
	}
	while ((str[idx] >= '0' && str[idx] <= '9'))
	{
		rst = rst * 10 + (str[idx] - '0');
		++idx;
	}
	return (rst * sgn);
}
