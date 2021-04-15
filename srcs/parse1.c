/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:39:37 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/15 11:58:18 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

// void				ft_parse_cmd_cut(t_cmd *cmd)
// {
// 	t_str			*str;
	
// 	str = ft_util_str_new();
// }

int					ft_parse_cmd(char *lin)
{
	// t_cmd			*cmd;
	// int				idx;

	// cmd = (t_cmd *)malloc(sizeof(t_cmd));
	// cmd->lin = lin;
	// idx = 0;
	// while (cmd->lin[idx])
	// {
	// 	if (ft_util_is_empty(cmd->lin[idx]))
	// 		++idx;
	// 	else if (cmd->lin[idx] == '$')
	// 		ft_parse_dollar(lin, &idx, cmd);
	// 	else if (cmd->lin[idx] == '\"')
	// 		ft_parse_double_quote(lin, &idx, cmd);
	// 	else if (cmd->lin[idx] == '\'')
	// 		ft_parse_single_quote(lin, &idx, cmd);
	// }
	// ft_parse_cmd_cut(cmd);

	t_cmd			*cmd;
	int				tm1;
	int				tm2;
	int				idx;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->nxt = NULL;
	cmd->pre = NULL;
	cmd->lin = lin;
	idx = 0;
	tm2 = 0;
	while (ft_util_is_empty(cmd->lin[idx]) == 1)
		++idx;
	tm1 = idx;
	while (ft_util_is_alpha(cmd->lin[tm1]) == 1)
		++tm1;
	if (!(cmd->cmd = (char *)malloc(sizeof(char) * (tm1 - idx + 1))))
		return (0);
	while (tm2 < (tm1 - idx))
	{
		cmd->cmd[tm2] = cmd->lin[idx + tm2];
		++tm2;
	}
	cmd->cmd[tm2] = '\0';
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
	cmd->arg[idx] = '\0';
	ft_util_cmd_lstaddback(cmd);
	return (1);
}

void				ft_parse(char *lin)
{
	char			**par;
	char			*path;
	char			**paths;
	pid_t			pid;
	int				rst;
	int				sta;
	int				i;

	pid = fork();
	if (pid == 0)
		// ft_parse_pid_zero(&paths)
	{
		// bin = ft_util_strdup("/bin/");
		// par = ft_util_split(lin, ' ');
		// rst = execve(ft_util_strjoin(bin, par[0]), par, g_mns->env_str);
		// if (rst == -1)
		// 	exit(0);
		// free(bin);
		// ft_util_freestrstr(par);
		// exit(0);
		printf("child\n");
		path = getenv("PATH");
		paths = ft_util_split(path, ':');
		i = 0;
		while (paths[i])
		{
			paths[i] = ft_util_chajoin(paths[i], '/');
			i++;
		}
		i = 0;
		par = ft_util_split(lin, ' ');
		while (paths[i])
		{
			rst = execve(ft_util_strjoin(paths[i], par[0]), par, g_mns->env_str);
			if (rst == -1)
				i++;
			else
				break ;
		}
		if (paths[i] == NULL)
			printf("U failed\n");
		printf("child1\n");
		printf("child2\n");
		if (rst == -1)
		{
			printf("child end by rst");
			exit(0);
		}
		ft_util_freestrstr(paths);
		ft_util_freestrstr(par);
		printf("child end");
		exit(0);
	}
	else if (pid > 0)
	{
		printf("mom\n");
		ft_parse_cmd(lin);
		if (ft_process() == -1)
			ft_exit_cmd();
		printf("mom end wait\n");
		waitpid(pid, &sta, 0);
		printf("mom end\n");
	}
}