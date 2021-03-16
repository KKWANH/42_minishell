/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:32:17 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/10/01 23:02:31 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*dup;

	size = ft_strlen(s1);
	dup = ft_calloc(size + 1, 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s1, size);
	dup[size] = 0;
	return (dup);
}
