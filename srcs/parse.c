/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:39:37 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/03/26 08:54:45 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

void				ft_parse(char *lin)
{
	char			**par;
	char			*bin;
	int				rst;
	pid_t			pid;
	int				sta;

	bin = ft_util_strdup("/bin/");
	par = ft_util_split(lin, ' ');
	pid = fork();
	if (pid == 0)
	{
		if (ft_util_strnstr(lin, "exit", ft_util_strlen(lin)))
			ft_exit_cmd();
		rst = execve(ft_util_strjoin(bin, par[0]), par, g_mns->env_str);
	}
	else if (pid > 0)
	{
		if (ft_util_strnstr(lin, "exit", ft_util_strlen(lin)))
			ft_exit_cmd();
		if (ft_util_strnstr(lin, "env", ft_util_strlen(lin)))
			ft_env_cmd();
		if (ft_util_strnstr(lin, "export", ft_util_strlen(lin)))
			if (ft_export_cmd(lin) == 0)
				ft_util_putstr_fd(ANSI_RED "zsh: " ANSI_RES "bad assignment\n", 1);
		waitpid(pid, &sta, 0);
	}
}