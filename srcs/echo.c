/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:32:00 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/06 15:33:43 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_mns				*g_mns;

void				ft_echo_ext(char *par)
{
	int idx;

	idx = 0;
	while (par[idx])
	{
		if ((ft_util_strcmp(&par[idx], "$?") == 0))
		{
			printf("%d", g_mns->ext);
			idx += 1;
		}
		else
			printf("%c", par[idx]);
		idx++;
	}
}

int					ft_echo_flagcheck(char *str)
{
	int idx;

	idx = 2;
	if (!(str[0] == '-') || !(str[1] == 'n'))
		return (0);
	while (str[idx])
	{
		if (str[idx] != 'n')
			return (0);
		idx++;
	}
	return (1);
}

int					ft_echo_before(t_par *par, int idx, int *flag)
{
	while (par->spl[idx])
	{
		if (ft_echo_flagcheck(par->spl[idx]))
		{
			*flag = 1;
			idx++;
		}
		else
			break ;
	}
	return (idx);
}

void				ft_echo_cmd(t_par *par)
{
	int idx;
	int flag;

	idx = 1;
	flag = 0;
	idx = ft_echo_before(par, idx, &flag);
	while (par->spl[idx])
	{
		// if ((ft_util_strnstr(par->spl[idx],
		// 				"$?", ft_util_strlen(par->spl[idx]))) != NULL)
		// 	ft_echo_ext(par->spl[idx]); //요건 좀 바꿔야할듯
		// else
			ft_util_putstr_fd(par->spl[idx], 1);
		if (par->spl[idx + 1] != NULL)
			write(1, " ", 1);
		idx++;
	}
	if (!flag)
		ft_util_putstr_fd("\n", 1);
	g_mns->ext = 0;
}
