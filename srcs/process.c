/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:56:32 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/23 09:39:14 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

int					ft_process(void)
{
	t_cmd			*tmp;

	tmp = ft_util_cmd_lstlast(g_mns->cmd);
	if (ft_util_strcmp(tmp->spl->str, "env") == 0)
		ft_env_cmd();
	if (ft_util_strcmp(tmp->spl->str, "pwd") == 0)
		ft_pwd_cmd();
	if (ft_util_strcmp(tmp->spl->str, "exit") == 0)
		ft_exit_cmd();
	// if (ft_util_strcmp(tmp->spl->str, "cd") == 0)
	// 	ft_cd_cmd();
	// if (ft_util_strcmp(tmp->spl->str, "echo") == 0)
	// 	ft_echo_cmd();
	// if (ft_util_strcmp(tmp->cmd, "export"))
	// 	if (ft_export_cmd(tmp->lin) == 0)
	// 		ft_util_putstr_fd(ANSI_RED "zsh: " ANSI_RES "bad assignment\n", 1);
	return (1);
}
