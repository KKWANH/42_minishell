/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:43:01 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/07 06:47:01 by kimkwanho        ###   ########.fr       */
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
	if (str == NULL)
		return (0);
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

char				*ft_util_strnstr(const char *hay, const char *nd, size_t ln)
{
	if (*nd == '\0')
		return ((char*)hay);
	while (ln != 0 && *hay != 0)
	{
		if (*hay == *nd)
		{
			if (ft_util_ndlchk(hay, nd, ln) == 1)
				return ((char*)hay);
		}
		++hay;
		--ln;
	}
	return (0);
}
