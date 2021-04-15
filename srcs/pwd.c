/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:43:10 by juhpark           #+#    #+#             */
/*   Updated: 2021/04/15 11:59:12 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void				ft_pwd_cmd(void)
{
	char	buf[1000];
	char	*tmp;

	tmp = getcwd(buf, 1000);
	write(1, buf, ft_util_strlen(buf));
}
