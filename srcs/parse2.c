/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 10:43:53 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/07 18:29:55 by juhpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void				ft_parse_quotes_big_sub(char **spl, int *i, char *rst)
{
	free(spl[*i]);
	spl[*i] = 0;
	spl[*i] = ft_util_strdup(rst);
	if (ft_util_strnstr(spl[*i], "$", ft_util_strlen(spl[*i])) != NULL)
		ft_parse_dollar(i, spl);
}

void				ft_parse_quotes_sml_sub(char **spl, int *i, char *rst)
{
	free(spl[*i]);
	spl[*i] = 0;
	spl[*i] = ft_util_strdup(rst);
}

void				ft_parse_split_count_sub_blank(char *lin, int *idx)
{
	++(*idx);
	if (lin[(*idx)] && lin[(*idx)] != ' ')
	{
		while (lin[(*idx)] && lin[(*idx)] != ' ')
			++(*idx);
		while (lin[(*idx)] && lin[(*idx)] == ' ')
			++(*idx);
	}
}

int					ft_parse_process_special_quotes
	(char **spl, int *idx, int sml_qou, int big_qou)
{
	int				jdx;

	jdx = 0;
	while (spl[*idx][jdx])
	{
		if (spl[*idx][jdx] == '\'')
		{
			if (sml_qou == CLOSE)
				sml_qou = SINGLE;
			else
				sml_qou = CLOSE;
		}
		if (sml_qou == SINGLE && spl[*idx][jdx] == '\"')
		{
			if (big_qou == CLOSE)
				big_qou = DOUBLE;
			else
				return (-1);
		}
		++jdx;
	}
	return (1);
}

int					ft_parse_switch_sub
	(char **spl, int *i, int *j, t_par **par)
{
	char			*s;

	if ((s = (ft_util_strnstr(spl[*i], ";", ft_util_strlen(spl[*i])))) != NULL)
	{
		(*par)->spl[*j] = NULL;
		(*par)->typ = TYPE_SEMI;
		return (ft_parse_semi(j, i, par));
	}
	if ((s = (ft_util_strnstr(spl[*i], "|", ft_util_strlen(spl[*i])))) != NULL)
	{
		(*par)->spl[*j] = NULL;
		(*par)->typ = TYPE_PIPE;
		return (ft_parse_semi(j, i, par));
	}
	return (0);
}
