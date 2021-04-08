/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:39:37 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/08 17:05:41 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

int					ft_parse_cmd(char *lin)
{
	t_cmd			*cmd;
	int				tm1;
	int				tm2;
	int				idx;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->lin = lin;
	idx = 0;
	tm2 = 0;
	while (ft_util_is_empty(cmd->lin[idx]) == 1)
		++idx;
	tm1 = idx;
	while (ft_util_is_alpha(cmd->lin[tm1]) == 1)
		++tm1;
	if (!(cmd->cmd = (char *)malloc(sizeof(char) * (tm1 - idx))))
		return (0);
	while (tm2 < (tm1 - idx))
	{
		cmd->cmd[tm2] = cmd->lin[idx + tm2];
		++tm2;
	}
	while (ft_util_is_alpha(cmd->lin[idx]) == 1)
		++idx;
	while (ft_util_is_empty(cmd->lin[idx]) == 1)
		++idx;
	tm1 = 0;
	tm2 = idx;
	while (cmd->lin[idx])
	{
		++idx;
		++tm1;
	}
	idx = 0;
	if (!(cmd->arg = (char *)malloc(sizeof(char) * tm1)))
		return (0);
	while (idx < tm1)
	{
		cmd->arg[idx] = cmd->lin[tm2 + idx];
		++idx;
	}
	ft_util_cmd_lstaddback(cmd);
	return (1);
}

void				ft_parse(char *lin)
{
	char			**par;
	char			*bin;
	pid_t			pid;
	int				rst;
	int				sta;

	pid = fork();
	if (pid == 0)
	{
		bin = ft_util_strdup("/bin/");
		par = ft_util_split(lin, ' ');
		rst = execve(ft_util_strjoin(bin, par[0]), par, g_mns->env_str);
		if (rst == -1)
			exit(0);
		free(bin);
		ft_util_freestrstr(par);
		exit(0);
	}
	else if (pid > 0)
	{
		ft_parse_cmd(lin);
		if (ft_process() == -1)
			ft_exit_cmd();
		waitpid(pid, &sta, 0);
	}
}