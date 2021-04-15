/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:56:32 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/15 11:58:57 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

int					ft_process(void)
{
	t_cmd			*tmp;

	tmp = ft_util_cmd_lstlast(g_mns->cmd);
	if (ft_util_strncmp(tmp->cmd, "exit", ft_util_strlen(tmp->cmd)) == 0)
		ft_exit_cmd();
	if (ft_util_strncmp(tmp->cmd, "env", ft_util_strlen(tmp->cmd)) == 0)
		ft_env_cmd();
	if (ft_util_strncmp(tmp->cmd, "pwd", ft_util_strlen(tmp->cmd)) == 0)
		ft_pwd_cmd();
	// if (ft_util_strnstr(tmp->cmd, "export", ft_util_strlen(tmp->cmd)))
	// 	if (ft_export_cmd(tmp->lin) == 0)
	// 		ft_util_putstr_fd(ANSI_RED "zsh: " ANSI_RES "bad assignment\n", 1);
	return (1);
}
