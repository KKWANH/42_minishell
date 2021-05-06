/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:19 by juhpark           #+#    #+#             */
/*   Updated: 2021/05/07 01:40:34 by kimkwanho        ###   ########.fr       */
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
				ret[i++] = ' ';
			ret[i++] = lin[j++];
			if (lin[j] && (lin[j] == '>' && lin[j - 1] == '>'))
			{
				ret[i++] = lin[j++];
				if (lin[j] && ft_util_is_empty(lin[j]))
					ret[i++] = ' ';
				continue ;
			}
			if (lin[j + 1] == '\0')
				break ;
			if (lin[j] != ' ')
				ret[i++] = ' ';
		}
		ret[i++] = lin[j++];
	}
	ret[i] = '\0';
	return (ret);
}

int				ft_parse_before_space(char *lin, t_quo *quo)
{
	int i;

	i = 0;
	while (lin[i])
	{
		if (lin[i] == '\'')
			quo->s_open++;
		else if (lin[i] == '\"')
			quo->d_open++;
		i++;
	}
	if (quo->s_open % 2 == 1 && quo->d_open % 2 == 1)
		return (0);
	if ((quo->s_open || quo->d_open) &&
			quo->s_open % 2 == 0 && quo->d_open % 2 == 0)
		return (-1);
	else
		return (1);
}

char			*ft_parse_space(char *lin)
{
	int		cnt;
	char	*ret;
	int		flg;
	t_quo	quo;

	quo.d_open = 0;
	quo.s_open = 0;
	if ((flg = ft_parse_before_space(lin, &quo)) == 0)
	{
		printf("asd\n");
		err_by_syntax(&g_mns->ext);
		return (0);
	}
	cnt = ft_count_sp_token(lin, flg);
	if (cnt < 0)
		return (0);
	ret = (char *)malloc(sizeof(char) * (ft_util_strlen(lin) + cnt + 1));
	if (!ret)
	{
		err_by("malloc error\n", &g_mns->ext);
		return (0);
	}
	else
		ret = ft_input_lin(lin, ret, 0, 0);
	return (ret);
	// int		cnt;
	// char	*ret;

	// cnt = ft_count_sp_token(lin);
	// if (cnt < 0)
	// 	return (0);
	// ret = (char *)malloc(sizeof(char) * (ft_util_strlen(lin) + cnt + 1));
	// if (!ret)
	// {
	// 	err_by("malloc error\n", &g_mns->ext);
	// 	return (0);
	// }
	// ret = ft_input_lin(lin, ret, 0, 0);
	// printf("test : %s\n", ret);
	// return (ret);
}
