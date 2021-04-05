/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:51:23 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/05 09:17:23 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mns				*g_mns;

void				ft_read_eof(char *lin)
{
	if (ft_util_strlen(lin) != 0)
		g_mns->tmp_char = lin;
	if (ft_util_strlen(g_mns->tmp_char) == 0)
	{
		printf("exit\n");
		exit(0);
	}
	ft_util_putstr_fd("  \b\b", 1);
}

int					main(int arc, char **arv, char **env)
{
	char			*lin;
	int				rst;

	if (!(g_mns = (t_mns *)malloc(sizeof(t_mns))))
		return (-1);
	g_mns->env_str = env;
	g_mns->env = ft_env_init();
	g_mns->pth = 0;
	g_mns->exit_code = 0;
	ft_signal_set();
	while (1)
	{
		ft_prompt_put_msg();
		while ((rst = get_next_line(0, &lin)) == 0)
			ft_read_eof(lin);
		free(lin);
		ft_parse(lin);
	}
	return (0);
}