/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 09:41:06 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/19 09:27:26 by kimkwanho        ###   ########.fr       */
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

int					ft_util_putchar(int tc)
{
	write(1, &tc, 1);
	return (0);
}

char				*ft_util_addcha(char *line, char c, int indx)
{
	char			*str;
	int				i;
	int				j;

	if (line == 0 && c == 0)
		return (0);
	if ((str = (char*)malloc(sizeof(char) * (ft_util_strlen(line) + 2))) == 0)
		return (0);
	i = 0;
	j = 0;
	while (line[i])
	{
		if (j == indx)
		{
			str[j] = c;
			j++;
			continue ;
		}
		str[j] = line[i];
		i++;
		j++;
	}
	free(line);
	str[j] = 0;
	return (str);
}

char				*ft_util_chaout(char *line, int indx)
{
	char			*str;
	int				i;
	int				j;
	int				len;

	if (line == 0)
		return (0);
	len = ft_util_strlen(line);
	if ((str = (char*)malloc(sizeof(char) * len)) == 0)
		return (0);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (j == indx)
		{
			j++;
			continue ;
		}
		str[i++] = line[j++];
	}
	free(line);
	str[i] = 0;
	return (str);
}

int					ft_util_is_num(char chr)
{
	if (chr >= '0' && chr <= '9')
		return (1);
	else
		return (0);
}
