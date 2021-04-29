/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:57:42 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/23 12:09:54 by juhpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

/*
 * 이거 인자 여러개 받았을때 에러 맹글어야함
*/

void				ft_exit_cmd(void)
{
	int tmp;

	tmp = 0;
	printf("exit\n");
//	printf("exit num : %d", g_mns->ext);
/*
	if (ft_util_strlen(g_mns->cmd->arg) != 0)
	{
		while (g_mns->cmd->arg[tmp])
		{
			if (!(ft_util_is_num(g_mns->cmd->arg[tmp])))
				err_by_exit(g_mns->cmd->arg, &g_mns->ext);
			tmp++;
		}
		tmp = ft_util_atoi(g_mns->cmd->arg);
		g_mns->ext = tmp;
	}
*/
	if (g_mns->ext != 0)
		exit(g_mns->ext);
	else
		exit(0);
}
