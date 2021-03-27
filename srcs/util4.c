/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 09:05:10 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/03/27 22:46:48 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int					ft_util_is_export(char chr)
{
	if ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z') ||
		chr == '_' || chr == '/' || chr == '\\')
		return (1);
	return (0);
}

int					ft_util_strcmp(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (-1);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[j])
			break ;
		i++;
		j++;
	}
	return (s1[i] - s2[i]);
}

void				ft_util_freestrstr(char **str)
{
	int				idx;

	idx = 0;
	while (str[idx])
		free(str[idx++]);
	free(str);
}
