/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:43:01 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/03/24 08:16:15 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int					ft_util_strchr(const char *str, int chr)
{
	int				idx;

	idx = 0;
	if (!str || !chr)
		return (-1);
	while (str[idx] != '\0')
	{ 
		if (str[idx] == chr)
			return (idx);
		++idx;
	}
	return (-1);
}

int					ft_util_strlen(char *str)
{
	int				cnt;

	cnt = 0;
	while (str[cnt])
		++cnt;
	return (cnt);
}

void				ft_util_putstr_fd(char *str, int fil)
{
	int				idx;

	idx = 0;
	if (fil < 0 || !str)
		return ;
	while (str[idx] != 0)
	{
		write(fil, &str[idx], 1);
		++idx;
	}
}

char				ft_util_ndlchk(const char *hay, const char *ndl, size_t len)
{
	while (*ndl != 0)
	{
		if (*hay != *ndl || len == 0)
			return (0);
		hay++;
		ndl++;
		len--;
	}
	return (1);
}

char				*ft_util_strnstr(const char *hay, const char *ndl, size_t len)
{
	if (*ndl == '\0')
		return ((char*)hay);
	while (len != 0 && *hay != 0)
	{
		if (*hay == *ndl)
		{
			if (ft_util_ndlchk(hay, ndl, len) == 1)
				return ((char*)hay);
		}
		++hay;
		--len;
	}
	return (0);
}
