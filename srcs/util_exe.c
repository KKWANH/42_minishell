/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:27:11 by juhpark           #+#    #+#             */
/*   Updated: 2021/05/07 17:53:21 by juhpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

void				ft_util_dup_fd(t_par *par)
{
	if (par->fd_in != -2)
		dup2(par->fd_in, 0);
	if (par->fd_out != -2)
		dup2(par->fd_out, 1);
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
	int				rst;

	rst = stat(path, &test);
	test.st_mode = test.st_mode & S_IFMT;
	if (test.st_mode == S_IFDIR)
	{
		printf("%s is directory\n", path);
		g_mns->ext = 126;
		return (0);
	}
	if (rst == -1)
		return (0);
	return (1);
}

void				ft_util_open_pipe(t_par *par)
{
	if (par->typ == TYPE_PIPE)
		dup2(par->fil[1], 1);
	if (par->pre && par->pre->typ == TYPE_PIPE)
		dup2(par->pre->fil[0], 0);
}

void				ft_util_close_pipe(t_par *par)
{
	if (par->pip == 1)
	{
		close(par->fil[1]);
		if (!par->nxt || par->typ != TYPE_PIPE)
			close(par->fil[0]);
	}
	if (par->pre && par->pre->typ == TYPE_PIPE)
		close(par->pre->fil[0]);
}
