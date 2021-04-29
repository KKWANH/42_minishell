/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:13:55 by juhpark           #+#    #+#             */
/*   Updated: 2021/04/29 23:13:37 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_mns				*g_mns;

void				ft_cd_cmd(char **inp)
{
	char			*hom;

	if (inp[1] == NULL)
	{
		hom = getenv("HOME");
		if (chdir(hom) == -1)
			err_by_chdir(inp[0], &g_mns->ext);
	}
	else if (chdir(inp[1]) == -1)
		err_by_chdir(inp[0], &g_mns->ext);
}

