/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:19 by juhpark           #+#    #+#             */
/*   Updated: 2021/05/07 10:39:14 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_mns				*g_mns;

void				err_by_syntax(int *ext)
{
	ft_util_putstr_fd(ANSI_RED, 2);
	ft_util_putstr_fd("minishell: syntax error near unexpected tocken\n", 2);
	ft_util_putstr_fd(ANSI_RES, 2);
	*ext = 258;
}

void				ft_quo_init(t_quo *quo)
{
	quo->d_open = 0;
	quo->s_open = 0;
	quo->type = CLOSE;
}

char				*ft_prase_space_quotes
	(char *lin, int *i, char *str, t_quo *quo)
{
	str = ft_util_chajoin(str, lin[*i]);
	if (lin[*i] == '\'')
		quo->type = SINGLE;
	else if (lin[*i] == '\"')
		quo->type = DOUBLE;
	++(*i);
	while (lin[*i])
	{
		str = ft_util_chajoin(str, lin[*i]);
		if ((quo->type == SINGLE && lin[*i] == '\'') ||
			(quo->type == DOUBLE && lin[*i] == '\"'))
		{
			quo->type = CLOSE;
			return (str);
		}
		++(*i);
	}
	return (NULL);
}

char				*ft_parse_space_sub(char *ret)
{
	err_by_syntax(&g_mns->ext);
	free(ret);
	return (NULL);
}

char				*ft_parse_space(char *lin, int i)
{
	t_quo			quo;
	char			*ret;

	ft_quo_init(&quo);
	ret = ft_util_strdup("");
	while (lin[i])
	{
		if (quo.type == CLOSE && (lin[i] == '\'' || lin[i] == '\"'))
		{
			if (!(ret = ft_prase_space_quotes(lin, &i, ret, &quo)))
				return (ft_parse_space_sub(ret));
		}
		else if (lin[i] == ';' || lin[i] == '|' ||
			lin[i] == '>' || lin[i] == '<')
			ret = ft_parse_sp_op(lin, ret, &i, &quo);
		else
			ret = ft_util_chajoin(ret, lin[i]);
		if (quo.type < 0)
			return (ft_parse_space_sub(ret));
		++i;
	}
	return (ret);
}
