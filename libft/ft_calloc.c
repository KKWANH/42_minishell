/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:23:44 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/09/29 12:32:53 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t cnt, size_t siz)
{
	void	*rst;

	rst = (void *)malloc(cnt * siz);
	if (rst == 0)
		return (0);
	ft_memset(rst, 0, cnt * siz);
	return (rst);
}
