/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 09:41:06 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/09 09:41:11 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char				*ft_util_chajoin(char *line, char c)
{
	char			*str;
	int				i;

	if (line == 0 && c == 0)
		return (0);
	if ((str = (char*)malloc(sizeof(char) * (ft_util_strlen(line) + 2))) == 0)
		return (0);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	free(line);
	str[i] = c;
	str[++i] = 0;
	return (str);
}