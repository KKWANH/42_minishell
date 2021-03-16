/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:12:24 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/10/02 12:08:20 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isset(char c, char const *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *str, char const *set)
{
	char	*rst;
	int		frt;
	int		end;
	int		len;

	if (!str || !set)
		return ((char *)str);
	end = ft_strlen(str) - 1;
	frt = 0;
	while (frt <= end && ft_isset(str[frt], set))
		++frt;
	while (0 <= end && ft_isset(str[end], set))
		--end;
	len = (end > frt) ? (end - frt + 1) : (0);
	if (len >= 2)
	{
		rst = ft_calloc(sizeof(char), len + 1);
		if (!rst)
			return (0);
		ft_strlcpy(rst, str + frt, len + 1);
		return (rst);
	}
	return (ft_strdup(""));
}
