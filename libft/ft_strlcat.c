/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:32:49 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/10/02 17:33:53 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	rst;
	size_t	ddx;
	size_t	sdx;

	ddx = ft_strlen(dst);
	sdx = ft_strlen(src);
	if (ddx >= dstsize || dstsize == 0)
		return (sdx + dstsize);
	if (dstsize < ddx)
		rst = dstsize + sdx;
	else
		rst = ddx + sdx;
	sdx = 0;
	while (ddx < dstsize - 1 && src[sdx] != '\0')
		dst[ddx++] = src[sdx++];
	dst[ddx] = '\0';
	return (rst);
}
