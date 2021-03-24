/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 08:21:38 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/03/24 08:39:02 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char				*ft_util_strjoin(char const *s1, char const *s2)
{
	char			*str;
	int				i;
	int				j;

	if (s1 == 0 && s2 == 0)
		return (0);
	if ((str = (char*)malloc(sizeof(char) * (ft_util_strlen((char*)s1)
						+ ft_util_strlen((char*)s2) + 1))) == 0)
		return (0);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	free((char*)s1);
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}

char				*ft_util_strdup(char *src)
{
	char			*dest;
	int				size;
	int				i;
	int				j;

	i = 0;
	j = 0;
	size = ft_util_strlen(src);
	dest = (char*)malloc(sizeof(char) * (size + 1));
	if (dest == 0)
		return (0);
	while (src[i] != 0)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = 0;
	return (dest);
}
