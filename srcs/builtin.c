/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:56:32 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/07 06:12:27 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

int					ft_builtin_check(char *cmd)
{
	if ((ft_util_strcmp(cmd, "exit") == 0) ||
		(ft_util_strcmp(cmd, "env") == 0) ||
		(ft_util_strcmp(cmd, "pwd") == 0) ||
		(ft_util_strcmp(cmd, "cd") == 0) ||
		(ft_util_strcmp(cmd, "export") == 0) ||
		(ft_util_strcmp(cmd, "echo") == 0) ||
		(ft_util_strcmp(cmd, "unset") == 0))
		return (1);
	else
		return (0);
}

int					ft_builtin(t_par *par)
{
	if (ft_util_strcmp(par->spl[0], "pwd") == 0)
		ft_pwd_cmd(par);
	else if (ft_util_strcmp(par->spl[0], "exit") == 0)
		ft_exit_cmd(par);
	else if (ft_util_strcmp(par->spl[0], "cd") == 0)
		ft_cd_cmd(par);
	else if (ft_util_strcmp(par->spl[0], "echo") == 0)
		ft_echo_cmd(par);
	else if (ft_util_strcmp(par->spl[0], "env") == 0)
		ft_env_cmd(0);
	else if (ft_util_strcmp(par->spl[0], "export") == 0)
		ft_export_cmd(par);
	else if (ft_util_strcmp(par->spl[0], "unset") == 0)
		ft_unset_cmd(par);
	else
		return (0);
	exit(g_mns->ext);
	return (g_mns->ext);
}
