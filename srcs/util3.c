/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:29:10 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/07 06:38:29 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int					ft_util_is_ascii(int chr)
{
	if (chr >= 0 && chr <= 127)
		return (1);
	else
		return (0);
}

char				**ft_util_split_ufailed(char **res, int num)
{
	int				i;

	i = 0;
	while (i < num)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}

char				*ft_util_split_input(char *res, char *s, char c)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (s[j] != c)
	{
		j++;
		if (s[j] == 0)
			break ;
	}
	res = (char*)malloc(sizeof(char) * (j + 1));
	if (res == 0)
		return (0);
	while (i < j)
	{
		res[i] = *s;
		i++;
		s++;
	}
	res[i] = 0;
	return (res);
}

int					ft_util_split_count(char *s, char c)
{
	int				i;
	int				count;

	i = 0;
	count = 0;
	if (!*s)
		return (0);
	if (s[i] == c)
	{
		while (s[i] == c)
			i++;
	}
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			count++;
		}
		i++;
	}
	return (count + 1);
}

char				**ft_util_split(char const *s, char c)
{
	char			**res;
	int				num;
	int				i;

	if (!s)
		return (0);
	num = ft_util_split_count((char*)s, c);
	if (!(res = (char**)malloc(sizeof(char*) * (num + 1))))
		return (0);
	i = 0;
	while (i < num)
	{
		while (*s == c && *s != 0)
			s++;
		if (!(res[i] = ft_util_split_input(res[i], (char*)s, c)))
			return (ft_util_split_ufailed(res, i));
		s += ft_util_strlen(res[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}
