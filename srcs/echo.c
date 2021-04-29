/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:31:00 by juhpark           #+#    #+#             */
/*   Updated: 2021/04/29 23:15:26 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_mns				*g_mns;

void				ft_echo_ext(char *par)
{
	int i;

	i = 0;
	while (par[i])
	{
		if ((ft_util_strcmp(&par[i], "$?") == 0))
		{
			printf("%d", g_mns->ext);
			i += 1;
		}
		else
			printf("%c", par[i]);
		i++;
	}
}

void				ft_echo_cmd(char **inp)
{
	int i;
	int flag;

	i = 1;
	flag = 0;
	while (inp[i])
	{
		if ((ft_util_strcmp(inp[1], "-n") == 0) &&
				(ft_util_strlen(inp[1]) == 2) && i == 1)
			flag++;
		if ((ft_util_strnstr(inp[i],
						"$?", ft_util_strlen(inp[i]))) != NULL)
			ft_echo_ext(inp[i]);
		else
			printf("%s", inp[i]);
		if (inp[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (!flag)
		printf("\n");
}
