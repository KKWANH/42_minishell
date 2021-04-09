/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:35:02 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/09 09:42:40 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

// int					ft_export_cmd_check(char *lin)
// {
	
// }

// void				ft_export_cmd_putenv(void)
// {
	
// }

// void				ft_export_cmd_process(char *lin)
// {
	
// }

/*
** HOW TO PROCESS COMMAND [EXPORT] by kkim
** 0. Check that argument is empty
** 0.1. if that so - sort env and put to command like [declare -x NAME="VALUE"]
** 1. Make list of argument. Of course seperate them to NAME and VALUE.
*/
// int					ft_export_cmd(char *lin)
// {
// 	int				rst;

// 	rst = ft_export_cmd_check(lin);
// 	if (rst == -1)
// 		return (0);
// 	if (rst == 2)
// 		return (1);
// 	if (rst == 1)
// 	{
// 		ft_export_cmd_putenv();
// 		return (1);
// 	}
// 	ft_export_cmd_process(lin);
// 	return (1);
// }