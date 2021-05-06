/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:19 by juhpark           #+#    #+#             */
/*   Updated: 2021/05/06 16:50:02 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_mns			*g_mns;

void			err_by_syntax(int *ext)
{
	ft_util_putstr_fd(ANSI_RED, 2);
	ft_util_putstr_fd("minishell: syntax error near unexpected tocken", 2);
	ft_util_putstr_fd(ANSI_RES, 2);
	*ext = 258;
}

char			*ft_input_lin(char *lin, char *ret, int i, int j)
{
	while (lin[j])
	{
		if (lin[j] == ';' || lin[j] == '|' || lin[j] == '<' || lin[j] == '>')
		{
			if (lin[j - 1] != ' ')
			{
				ret[i] = ' ';
				i++;
			}
			ret[i++] = lin[j++];
			if (lin[j + 1] == '\0')
				break ;
			if (lin[j] != ' ' || (lin[j - 1] == '>' && lin[j] != '>'))
			{
				ret[i] = ' ';
				i++;
			}
		}
		ret[i++] = lin[j++];
	}
	ret[i] = '\0';
	return (ret);
}

char			*ft_parse_space(char *lin)
{
	int		cnt;
	char	*ret;

	cnt = ft_count_sp_token(lin);
	if (cnt < 0)
		return (0);
	ret = (char *)malloc(sizeof(char) * (ft_util_strlen(lin) + cnt + 1));
	if (!ret)
	{
		err_by("malloc error\n", &g_mns->ext);
		return (0);
	}
	ret = ft_input_lin(lin, ret, 0, 0);
	return (ret);
}
