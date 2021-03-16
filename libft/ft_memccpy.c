/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:20:40 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/10/01 23:01:22 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			indx;
	int				occr;
	unsigned char	*src_;

	src_ = (unsigned char *)src;
	indx = 0;
	occr = 0;
	while (indx < n && src_[indx] && !occr)
	{
		occr = ((src_)[indx] == (unsigned char)c) ? 1 : 0;
		++indx;
	}
	if (occr)
	{
		ft_memcpy(dst, src_, indx);
		return (dst + indx);
	}
	else
	{
		ft_memcpy(dst, src_, n);
		return (0);
	}
}
