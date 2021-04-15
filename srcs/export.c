// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   export.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/03/24 15:35:02 by kimkwanho         #+#    #+#             */
// /*   Updated: 2021/04/11 10:50:57 by kimkwanho        ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../minishell.h"

// extern t_mns		*g_mns;

// /*
// ** HOW TO PROCESS CHECKING FOR LINE
// **	while loop
// **	 0. if [ ] : skip
// **	 1. if ["] or ['] : get str.
// **	  1.0. if doesn't close with ["] or ['] : return -1
// **	 2. if str(name) doesn't have mate;str(value) : ignore it
// **	 3. if [$] : get all alpha until another character comes, process it to str
// **	 4. if 
// */
// int					ft_export_cmd_check(t_cmd *cur)
// {
// 	int				idx;
// 	int				flg;

// 	idx = 0;
// 	flg = 0;
// 	while (cur->arg[idx])
// 	{
// 		if (ft_util_is_empty(cur->arg[idx]))
// 			++idx;
// 		else if (cur->arg[idx] == '"')
// 		{
			
// 		}
// 		// else if (cur->arg[idx] == '=')
// 	}
// }

// void				ft_export_cmd_putenv(void)
// {
	
// }

// void				ft_export_cmd_process(void)
// {
	
// }

// /*
// ** HOW TO PROCESS COMMAND [EXPORT] by kkim
// **	0. Check that argument is empty
// **	 0.0. if that so - sort env and put to command like [declare -x NAME="VALUE"]
// **	1. Make list of argument. Of course seperate them to NAME and VALUE.
// */
// int					ft_export_cmd(t_cmd *cur)
// {
// 	int				rst;

// 	rst = ft_export_cmd_check(cur);
// 	if (rst == -1)
// 		return (0);
// 	if (rst == 2)
// 		return (1);
// 	if (rst == 1)
// 	{
// 		ft_export_cmd_putenv();
// 		return (1);
// 	}
// 	ft_export_cmd_process();
// 	return (1);
// }