/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:13:55 by juhpark           #+#    #+#             */
/*   Updated: 2021/04/23 09:38:31 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_mns				*g_mns;

// void				ft_cd_cmd(void)
// {
// 	char *home;

// 	if (g_mns->par[1] == NULL)
// 	{
// 		home = getenv("HOME");
// 		if (chdir(home) == -1)
// 			err_by_chdir(g_mns->cmd->arg, &g_mns->ext);
// 	}
// 	else if (chdir(g_mns->par[1]) == -1)
// 		err_by_chdir(g_mns->cmd->arg, &g_mns->ext);
// }

