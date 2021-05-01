/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:32:00 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/01 22:33:03 by kimkwanho        ###   ########.fr       */
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

int					ft_flag_check(char *str)
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

int					ft_before_echo(t_par *par, int idx, int *flag)
{
	while (par->spl[idx])
	{
		if (ft_flag_check(par->spl[idx]))
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
	idx = ft_before_echo(par, idx, &flag);
	while (par->spl[idx])
	{
		if ((ft_util_strnstr(par->spl[idx],
						"$?", ft_util_strlen(par->spl[idx]))) != NULL)
			ft_echo_ext(par->spl[idx]); //요건 좀 바꿔야할듯
		else
			ft_util_putstr_fd(par->spl[idx], 1);
		if (par->spl[idx + 1] != NULL)
			printf(" ");
		idx++;
	}
	if (!flag)
		printf("\n");
}

// '\'.. 과연 어찌 되었을까..?
