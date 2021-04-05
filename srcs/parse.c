/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:39:37 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/05 09:18:46 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

void				print_cmd(void)
{
	t_cmd			*tmp;

	tmp = g_mns->cmd;
	printf("-----------\n");
	while (tmp)
	{
		printf("[%s]:[%s]\n", tmp->cmd, tmp->lin);
		if (tmp->nxt)
			tmp = tmp->nxt;
		else
			break ;
	}
	printf("-----------\n");
}

int					ft_parse_switch(char *lin)
{
	t_cmd			*cmd;
	int				tm1;
	int				tm2;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->lin = lin;
	cmd->stt = 0;
	tm2 = 0;
	while (ft_util_is_empty(cmd->lin[cmd->stt]) == 1)
		++cmd->stt;
	tm1 = cmd->stt;
	while (ft_util_is_alpha(cmd->lin[tm1]) == 1)
		++tm1;
	if (!(cmd->cmd = (char *)malloc(sizeof(char) * (tm1 - cmd->stt))))
		return (0);
	while (tm2 < (tm1 - cmd->stt))
	{
		cmd->cmd[tm2] = cmd->lin[cmd->stt + tm2];
		++tm2;
	}
	while (ft_util_is_alpha(cmd->lin[cmd->stt]) == 1 ||
		ft_util_is_empty(cmd->lin[cmd->stt]) == 1)
		++cmd->stt;
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
		ft_parse_switch(lin);
		if (ft_process() == 0)
			ft_exit_cmd();
		waitpid(pid, &sta, 0);
	}
}