/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:58:57 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/10/02 17:34:14 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned const char)c)
	{
		if (!*s++)
			return (NULL);
	}
	return ((char *)s);
}
