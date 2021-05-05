/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:27:11 by juhpark           #+#    #+#             */
/*   Updated: 2021/05/04 21:43:55 by juhpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns			*g_mns;

void					ft_util_dup_fd(t_par *par)
{
	if (par->fd_in != -2)
	{
		if (dup2(par->fd_in, 0) == -1)
		{
			err_by("fd error\n", &g_mns->ext);
			exit(1);
		}
	}
	if (par->fd_out != -2)
	{
		if (dup2(par->fd_out, 1) == -1)
		{
			err_by("fd error\n", &g_mns->ext);
			exit(1);
		}
	}
}

char				**ft_util_parse_path(void)
{
	char			*pth;
	char			**rst;
	int				idx;

	pth = ft_util_env_search("PATH");
	rst = ft_util_split(pth, ':');
	idx = 0;
	while (rst[idx])
	{
		rst[idx] = ft_util_chajoin(rst[idx], '/');
		++idx;
	}
	return (rst);
}

int					ft_util_is_execable(char *path)
{
	struct stat		test;

	if (stat(path, &test) == 0)
		return (1);
	else
		return (0);
}

//파이프는 fil[0]으로 받아서 fil[1]로 나감

void				ft_util_open_pipe(t_par *par)
{
	if (par->typ == TYPE_PIPE) //지금 프로세스가 파이프 일때 
		dup2(par->fil[1], 1); //stdout 에 fil[1] 을 넘겨주어서 다음 프로세스로 넘겨줌
	if (par->pre && par->pre->typ == TYPE_PIPE) //앞놈이 파이프일때
		dup2(par->pre->fil[0], 0); //앞에 파이프가 있을때 넘겨준 앞부분의 fil[0]을 stdin으로 받음
}

void				ft_util_close_pipe(t_par *par)
{
	if (par->pip == 1)
		close(par->fil[1]); //프로세싱 끝나고 받아둔 파이프는 역할 다했으니 쫑
		if (!par->nxt || par->typ != TYPE_PIPE) //만약 지금 프로세스가 파이프의 맨 마지막 지점아라면
			close(par->fil[0]); //맨끝->출력해야하니 파이프 필요없음
	if (par->pre && par->pre->typ == TYPE_PIPE) //앞부분이 파이프일때 앞 노드에서 fil[1]을 가져와서 다썼으니 끝
		close(par->pre->fil[0]);
}
