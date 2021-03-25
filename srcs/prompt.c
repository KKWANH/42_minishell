/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:23:20 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/03/25 13:54:24 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*mns;

void				ft_prompt_put_msg(void)
{
	// printf("%s%s%s", ANSI_RES, mns->pth, ANSI_RES);
	ft_util_putstr_fd(ANSI_BLU "- [kkim-juhpark]$ " ANSI_RES, 1);
}