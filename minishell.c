/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:51:23 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/03/24 08:39:43 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mns			*mns;

int					main(int arc, char **arv, char **env)
{
	char			*lin;
	int				rst;

	if (!(mns = (t_mns *)malloc(sizeof(t_mns))))
		return (-1);
	mns->env = ft_env_init(env);
	mns->pth = 0;
	ft_signal_set();
	while (1)
	{
		// write(1, "\ndbg: 1\n", 8);
		ft_prompt_put_msg();
		rst = get_next_line(0, &lin);
		if (rst >= 0)
		{
			printf("%s\n", lin);
			free(lin);
		}
		if (ft_util_strnstr(lin, "exit", ft_util_strlen(lin)))
			exit(0);
		if (ft_util_strnstr(lin, "env", ft_util_strlen(lin)))
		{
			while (mns->env)
			{
				printf("%s = %s\n", mns->env->nam, mns->env->val);
				mns->env = mns->env->nxt;
			}
		}
	}
	return (0);
}