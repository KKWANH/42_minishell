/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:39:37 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/01 22:35:49 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

int					ft_execve_nonap(char **par, int i)
{
	char			**paths;
	int				ret;

	paths = ft_util_parse_path();
	while (paths[i])
	{
		paths[i] = ft_util_strjoin(paths[i], par[0]);
		ret = execve(paths[i], par, g_mns->env_str);
		if (ret == -1)
			i++;
		else
			break ;
	}
	if (paths[i] == NULL)
	{
		ft_util_freestrstr(paths);
		return (-1);
	}
	ft_util_freestrstr(paths);
	return (1);
}

void				ft_execve(t_par *par, int res, int sta)
{
	pid_t			pid;

	pid = fork();
	if (pid < 0)
		err_by_pid(&g_mns->ext);
	else if (pid == 0)
	{
		// ft_util_open_pipe(par);
		if (ft_parse_check(par->spl[0]) == 1)
			ft_builtin(par);
		else if (par->spl[0][0] == '/')
			res = execve(par->spl[0], par->spl, g_mns->env_str);
		else
			res = ft_execve_nonap(par->spl, 0);
		if (res < 0)
			err_by_command(par->spl[0], &g_mns->ext);
	}
	else if (pid > 0)
	{
		waitpid(pid, &sta, 0);
		if (WIFEXITED(sta)) //자식 프로세스 상태값을 받아서
			g_mns->ext = WEXITSTATUS(sta); //종료값을 저장
	}
}

void				ft_exe_loop(t_par *par)
{
	char			*pth;

	while (par)
	{
		if (par->typ == TYPE_PIPE || (par->pre && par->pre->typ == TYPE_PIPE))
		{
			par->pip = 1;
			if (pipe(par->fil) == -1)
				return ;
		}
		if (ft_parse_check(par->spl[0]) == 1)
		{
			if (par->pip == 1)
				ft_execve(par, 0, 0);
			else
				ft_builtin(par);
		}
		else if (par->spl[0][0] == '/') //절대경로인가 
		{
			if (ft_util_is_execable(par->spl[0]))
				ft_execve(par, 0, 0);
			else
				err_by_path(par->spl[0], &g_mns->ext);
		}
		else if ((pth = getenv("PATH")) != NULL) //얘는 나중에 바뀔수도?->getenv가 아닌 다른방시으로..
			ft_execve(par, 0, 0);
		else
			err_by_path(par->spl[0], &g_mns->ext);
		ft_util_close_pipe(par);
		par = par->nxt;
	}
}

void				ft_exe(char *lin)
{
	t_par			*par;
	t_cmd			*cmd;

	par = NULL;
	cmd = NULL;
	if (lin[0] == '\0')
		return ;
	par = ft_parse_cmd(lin, par);
	ft_exe_loop(par);
	// cmd->lin = lin;
	// ft_util_cmd_lstaddback(cmd);
	ft_parse_list_free(&par);
}

/*
	cmd = ft_util_cmd_lstlast(g_mns->cmd);

	// ft_util_putstr_fd("[", 1);
	// ft_util_putstr_fd(lin, 1);
	// ft_util_putstr_fd("]\n", 1);
	if (ft_parse_cmd(lin) == 0)
		return ;
	cmd = ft_util_cmd_lstlast(g_mns->cmd);
	if (cmd->spl[0] == NULL) //엔터키만 받았을때
		return ; //이또한 임시 파싱해서 달라질 수 있음
	// pipe(fd);
	if (ft_parse_check(cmd->spl[0]) == 1)
		ft_builtin();
	else if (lin[0] == '/') //절대경로인가 
	{
		if (ft_util_exe_is_execable(cmd->spl[0]))
			ft_execve(fd, cmd->spl, 0, 0);
		else
			err_by_path(cmd->spl[0], &g_mns->ext);
	}
	else if ((p = getenv("PATH")) != NULL) //얘는 나중에 바뀔수도?
		ft_execve(fd, cmd->spl, 0, 0);
	else
		err_by_path(cmd->spl[0], &g_mns->ext);
	ft_util_freestrstr(cmd->spl); //임시 파싱 해제
	// printf("exit code : %d\n", g_mns->ext);
*/