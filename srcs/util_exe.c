/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:27:11 by juhpark           #+#    #+#             */
/*   Updated: 2021/04/29 23:33:28 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

char				**ft_util_exe_parse_path(void)
{
	char			*pth;
	char			**rst;
	int				idx;

	pth = getenv("PATH");
	rst = ft_util_split(pth, ':');
	idx = 0;
	while (rst[idx])
	{
		rst[idx] = ft_util_chajoin(rst[idx], '/');
		++idx;
	}
	return (rst);
}

int					ft_util_exe_is_execable(char *path)
{
	struct stat		test;

	if (stat(path, &test) == 0)
		return (1);
	else
		return (0);
}
