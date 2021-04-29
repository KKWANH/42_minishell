/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:43:10 by juhpark           #+#    #+#             */
/*   Updated: 2021/04/29 23:11:20 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void				ft_pwd_cmd(char **inp)
{
	char			buf[1000];
	char			*tmp;

	if (inp[1] != NULL)
		ft_util_putstr_fd(ANSI_RED "pwd: " ANSI_RES "too many arguments\n", 1);
	else
	{
		tmp = getcwd(buf, 1000);
		write(1, buf, ft_util_strlen(buf));
		write(1, "\n", 1);
	}
}
