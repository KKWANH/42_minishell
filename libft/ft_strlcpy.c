/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:30:24 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/10/01 23:02:48 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	src_size;
	size_t	num;

	if (dst == 0 && src == 0)
		return (0);
	src_size = ft_strlen(src);
	num = 0;
	while (num < src_size && num + 1 < dst_size)
	{
		dst[num] = src[num];
		++num;
	}
	if (dst_size > 0)
		dst[num] = 0;
	return (src_size);
}
