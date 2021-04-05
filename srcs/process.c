/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 09:10:46 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/05 09:18:50 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

int					ft_process()
{
	t_cmd			*tmp;

	tmp = ft_util_cmd_lstlast(g_mns->cmd);
	if (ft_util_strnstr(tmp->lin, "exit", ft_util_strlen(tmp->lin)))
			ft_exit_cmd();
	if (ft_util_strnstr(tmp->lin, "env", ft_util_strlen(tmp->lin)))
		ft_env_cmd();
	if (ft_util_strnstr(tmp->lin, "export", ft_util_strlen(tmp->lin)))
		if (ft_export_cmd(tmp->lin) == 0)
			ft_util_putstr_fd(ANSI_RED "zsh: " ANSI_RES "bad assignment\n", 1);
	return (1);
}