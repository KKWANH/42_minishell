/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:25:20 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/10/01 22:57:29 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_bzero(void *str, size_t num)
{
	size_t	idx;

	idx = 0;
	while (idx < num)
	{
		((unsigned char *)str)[idx] = 0;
		++idx;
	}
	return (str);
}
