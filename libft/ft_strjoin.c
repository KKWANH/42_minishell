/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:03:11 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/09/29 14:04:44 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *st1, char const *st2)
{
	char	*rst;
	size_t	ln1;
	size_t	ln2;

	if (st1 == 0 && st2 == 0)
		return (0);
	ln1 = ft_strlen(st1);
	ln2 = ft_strlen(st2);
	if ((rst = (char *)malloc(sizeof(char) * (ln1 + ln2 + 1))) == 0)
		return (0);
	ft_memcpy(rst, st1, ln1);
	ft_memcpy(rst + ln1, st2, ln2);
	rst[ln1 + ln2] = 0;
	return (rst);
}
