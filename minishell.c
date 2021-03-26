/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:51:23 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/03/26 08:54:09 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mns				*g_mns;

int					main(int arc, char **arv, char **env)
{
	char			*lin;
	int				rst;

	if (!(g_mns = (t_mns *)malloc(sizeof(t_mns))))
		return (-1);
	g_mns->env_str = env;
	g_mns->env = ft_env_init();
	g_mns->pth = 0;
	ft_signal_set();
	while (1)
	{
		ft_prompt_put_msg();
		rst = get_next_line(0, &lin);
		if (rst >= 0)
			ft_parse(lin);
	}
	return (0);
	
}