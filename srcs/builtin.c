/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:56:32 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/04 00:06:02 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

int					ft_parse_check(char *cmd)
{
	if ((ft_util_strcmp(cmd, "exit") == 0) ||
		(ft_util_strcmp(cmd, "env") == 0) ||
		(ft_util_strcmp(cmd, "pwd") == 0) ||
		(ft_util_strcmp(cmd, "cd") == 0) ||
		(ft_util_strcmp(cmd, "expose") == 0) ||
		(ft_util_strcmp(cmd, "echo") == 0) ||
		(ft_util_strcmp(cmd, "unset") == 0))
		return (1);
	else
		return (0);
}

int				ft_builtin_exe(t_par *par)
{
	// printf("%s %d %d %d %d %d\n", par->spl[0], ft_util_strcmp(par->spl[0], "pwd"), ft_util_strcmp(par->spl[0], "exit"), ft_util_strcmp(par->spl[0], "cd"), ft_util_strcmp(par->spl[0], "echo"), ft_util_strcmp(par->spl[0], "env"));
	if (ft_util_strcmp(par->spl[0], "pwd") == 0)
		ft_pwd_cmd(par);
	else if (ft_util_strcmp(par->spl[0], "exit") == 0)
		ft_exit_cmd(par);
	else if (ft_util_strcmp(par->spl[0], "cd") == 0)
	 	ft_cd_cmd(par);
	else if (ft_util_strcmp(par->spl[0], "echo") == 0)
		ft_echo_cmd(par);
	else if (ft_util_strcmp(par->spl[0], "env") == 0)
		ft_env_cmd(NULL);
	// if (ft_util_strcmp(tmp->cmd, "export"))
	// 	if (ft_export_cmd(tmp->lin) == 0)
	// 		ft_util_putstr_fd(ANSI_RED "zsh: " ANSI_RES "bad assignment\n", 1);
	//else if (ft_util_strcmp(tmp->cmd, "unset"))
	//	ft_unset_cmd(par);
	return (g_mns->ext);
}

void				ft_builtin_fork(t_par *par, int sta)
{
	pid_t			pid;

	pid = fork();
	if (pid < 0)
		err_by_pid(&g_mns->ext);
	else if (pid == 0)
	{
		ft_util_open_pipe(par);
		if (par->fd_in != -2)
			dup2(par->fd_in, 0);
		if (par->fd_out != -2)
			dup2(par->fd_out, 1);
		ft_builtin_exe(par);
		exit(g_mns->ext);
	}
	else if (pid > 0)
	{
		waitpid(pid, &sta, 0);
		if (WIFEXITED(sta))
			g_mns->ext = WEXITSTATUS(sta);
	}
}

void				ft_builtin(t_par *par)
{
	if (par->pip)
		ft_builtin_fork(par, 0);
	else if (ft_util_strcmp(par->spl[0], "pwd") == 0)
		ft_builtin_fork(par, 0);
	else if (ft_util_strcmp(par->spl[0], "exit") == 0 && !par->pip)
		ft_exit_cmd(par);
	else if (ft_util_strcmp(par->spl[0], "exit") == 0)
		ft_builtin_fork(par, 0);
	else if (ft_util_strcmp(par->spl[0], "cd") == 0)
	 	ft_cd_cmd(par);
	else if (ft_util_strcmp(par->spl[0], "echo") == 0)
		ft_builtin_fork(par, 0);
	else if (ft_util_strcmp(par->spl[0], "env") == 0)
		ft_builtin_fork(par, 0);
	// if (ft_util_strcmp(tmp->cmd, "export"))
	// 	if (ft_export_cmd(tmp->lin) == 0)
	// 		ft_util_putstr_fd(ANSI_RED "zsh: " ANSI_RES "bad assignment\n", 1);
}
