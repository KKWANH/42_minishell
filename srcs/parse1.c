/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:39:37 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/23 09:34:27 by kimkwanho        ###   ########.fr       */
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

char				**ft_parse_path(void)
{
	char			*pth;
	char			**rst;
	int				idx;

	pth = ft_env_search("PATH");
	rst = ft_util_split(pth, '/');
	idx = 0;
	while (rst[idx])
	{
		rst[idx] = ft_util_chajoin(rst[idx], '/');
		++idx;
	}
	return (rst);
}

void				ft_parse_else(char *lin)
{
	int				rst;
	int				sta;
	pid_t			pid;
	char			**par;
	char			*bin;

	pid = fork();
	if (pid < 0)
		err_by_pid(&g_mns->ext);
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
		waitpid(pid, &sta, 0);
	//이걸 빌트인일때
	//PATH 거치는 명령어일때
	//절대경로 명령어일때
	//2, 3인 경우에 fork 시전
	//pipe 타이밍은 여기서 먼저 선언, 이후에 나눔
	//아님 에러출력
}

void				ft_parse(char *lin)
{
	t_cmd			*tmp;

	ft_parse_cmd(lin);
	tmp = ft_util_cmd_lstlast(g_mns->cmd);
	if (ft_parse_check(tmp->spl->str) == 1)
		ft_process();
	/*
	else if(lin[0] == '/')
		다른 뭐시기
	else if()
	{
		paths = get_paths();
		앞의 else if 들갔을때 동일한 함수
	}
	else
		err_by_command(파싱 첫 단어, &g_mns->ext);
	*/
	else
		ft_parse_else(lin);
}