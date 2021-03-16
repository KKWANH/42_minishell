/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 23:03:14 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/10/01 23:03:56 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *st1, const char *st2, size_t num)
{
	size_t idx;

	idx = 0;
	while (idx < num && (st1[idx] || st2[idx]))
	{
		if (st1[idx] != st2[idx])
			return ((unsigned char)st1[idx] - (unsigned char)st2[idx]);
		++idx;
	}
	return (0);
}
