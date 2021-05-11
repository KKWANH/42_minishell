/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:33:06 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/07 18:09:23 by juhpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

int					ft_parse_quotes_big(char **spl, int *i, int *j)
{
	char			*rst;
	t_quo			quo;

	rst = ft_util_strdup("");
	ft_quo_init(&quo);
	while (spl[*i][*j])
	{
		if (spl[*i][*j] == '\"')
		{
			++(*j);
			if (quo.type == CLOSE)
			{
				quo.type = DOUBLE;
				continue ;
			}
			else if (quo.type == DOUBLE)
			{
				quo.type = CLOSE;
				continue ;
			}
		}
		rst = ft_util_chajoin(rst, spl[*i][(*j)++]);
	}
	ft_parse_quotes_big_sub(spl, i, rst);
	return (0);
}

int					ft_parse_quotes_sml(char **spl, int *i, int *j)
{
	char			*rst;
	t_quo			quo;

	rst = ft_util_strdup("");
	ft_quo_init(&quo);
	while (spl[*i][*j])
	{
		if (spl[*i][*j] == '\'')
		{
			++(*j);
			if (quo.type == CLOSE)
			{
				quo.type = SINGLE;
				continue ;
			}
			else if (quo.type == SINGLE)
			{
				quo.type = CLOSE;
				continue ;
			}
		}
		rst = ft_util_chajoin(rst, spl[*i][(*j)++]);
	}
	ft_parse_quotes_sml_sub(spl, i, rst);
	return (0);
}

int					ft_parse_semi(int *jdx, int *idx, t_par **par)
{
	t_par *new;

	*jdx = 0;
	*idx += 1;
	new = ft_util_parse_init();
	if (*par)
	{
		(*par)->nxt = new;
		new->pre = (*par);
	}
	*par = new;
	return (1);
}

int					ft_parse_process_special
	(char **spl, t_par **par, int *i, int *j)
{
	char			*s;
	int				tmp;
	int				rst;

	tmp = 0;
	rst = ft_parse_process_special_quotes(spl, i, 0, 0);
	if ((s = (ft_util_strnstr(spl[*i], "\"",
						ft_util_strlen(spl[*i])))) != NULL && rst != -1)
		return (ft_parse_quotes_big(spl, i, &tmp));
	if ((s = (ft_util_strnstr(spl[*i], "\'", ft_util_strlen(spl[*i])))) != NULL)
		return (ft_parse_quotes_sml(spl, i, &tmp));
	if ((s = (ft_util_strnstr(spl[*i], "$", ft_util_strlen(spl[*i])))) != NULL)
		return (ft_parse_dollar(i, spl));
	return (ft_parse_switch_sub(spl, i, j, par));
}

t_par				*ft_parse_cmd(char *lin, t_par *par)
{
	int				idx;
	int				jdx;
	char			**spl;
	char			*tmp;

	idx = 0;
	jdx = 0;
	if (!(tmp = ft_parse_space(lin, 0)))
		return (0);
	if (par == NULL)
		par = ft_util_parse_init();
	spl = ft_parse_split(tmp);
	free(tmp);
	while (spl[idx])
	{
		if (ft_parse_process_special(spl, &par, &idx, &jdx) == 1)
			continue ;
		par->spl[jdx] = ft_util_strdup(spl[idx]);
		++idx;
		++jdx;
	}
	par->spl[jdx] = NULL;
	ft_util_parse_list_rewind(&par);
	ft_util_freestrstr(spl);
	return (par);
}
