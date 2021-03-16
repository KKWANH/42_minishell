/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 13:56:56 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/10/01 23:04:20 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *str, unsigned int stt, size_t len)
{
	size_t	idx;
	size_t	siz;
	char	*rst;

	idx = 0;
	rst = (char *)malloc(sizeof(char) * (len + 1));
	if (!str || !rst)
		return (NULL);
	siz = ft_strlen(str);
	while (idx < len && idx + stt < siz)
	{
		rst[idx] = str[stt + idx];
		++idx;
	}
	rst[idx] = '\0';
	return (rst);
}
