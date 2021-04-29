/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:40:05 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/29 23:50:11 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

void				ft_prompt_put_msg(void)
{
	ft_util_putstr_fd(ANSI_BLU " - ", 1);
	ft_util_putstr_fd(getenv("USER"), 1);
	ft_util_putstr_fd(ANSI_RES "'s minishell$ ", 1);
}

void				ft_prompt_intro(void)
{
	int				fil;
	char			buf;

	fil = open("srcs/prompt_ascii.txt", O_RDONLY);
	while (read(fil, &buf, 1) > 0)
		write(1, &buf, 1);
	close(fil);
}
