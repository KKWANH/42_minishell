/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:02:14 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/03/23 14:27:10 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void				ft_signal_handle(int sig)
{
	if (sig == 2)
	{
		ft_util_putstr_fd("\b\b \b\b\n", 1);
		ft_prompt_put_msg();
	}
	if (sig == 2)
	{
		ft_util_putstr_fd("\b\b \b\b\n", 1);
		ft_util_putstr_fd("exit", 1);
	}
}

void				ft_signal_set(void)
{
	signal(2, ft_signal_handle);
	signal(15, ft_signal_handle);
}