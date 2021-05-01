/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:43:10 by juhpark           #+#    #+#             */
/*   Updated: 2021/05/01 22:25:52 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void				ft_pwd_cmd(t_par *par)
{
	char	buf[1000];
	char	*ret;

	ret = getcwd(buf, 1000);
	if (*ret == -1 && par->pip == 1)
	{
		ft_util_putstr_fd(ANSI_RED, 2);
		ft_util_putstr_fd("minishell: pwd error\n", 2);
		ft_util_putstr_fd(ANSI_RES, 2);
		return ;
	}
	write(1, buf, ft_util_strlen(buf));
	write(1, "\n", 1);
}
