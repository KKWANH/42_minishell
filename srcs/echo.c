/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:31:00 by juhpark           #+#    #+#             */
/*   Updated: 2021/04/20 19:56:10 by juhpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
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

void				ft_echo_cmd(void)
{
	int i;
	int flag;

	i = 1;
	flag = 0;
	while (g_mns->par[i])
	{
		if ((ft_util_strcmp(g_mns->par[1], "-n") == 0) &&
				(ft_util_strlen(g_mns->par[1]) == 2) && i == 1)
			flag++;
		if ((ft_util_strnstr(g_mns->par[i],
						"$?", ft_util_strlen(g_mns->par[i]))) != NULL)
			ft_echo_ext(g_mns->par[i]);
		else
			printf("%s", g_mns->par[i]);
		if (g_mns->par[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (!flag)
		printf("\n");
}
*/
