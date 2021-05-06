/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:33:06 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/07 05:59:21 by kimkwanho        ###   ########.fr       */
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
			if (quo.type == CLOSE)
			{
				quo.type = DOUBLE;
				++(*j);
				continue ;
			}
			else if (quo.type == DOUBLE)
			{
				quo.type = CLOSE;
				++(*j);
				continue ;
			}
		}
		rst = ft_util_chajoin(rst, spl[*i][*j]);
		++(*j);
	}
	free(spl[*i]);
	spl[*i] = 0;
	spl[*i] = ft_util_strdup(rst);
	if (ft_util_strnstr(spl[*i], "$", ft_util_strlen(spl[*i])) != NULL)
		ft_parse_dollar(i, spl);
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
			if (quo.type == CLOSE)
			{
				quo.type = SINGLE;
				++(*j);
				continue ;
			}
			else if (quo.type == SINGLE)
			{
				quo.type = CLOSE;
				++(*j);
				continue ;
			}
		}
		rst = ft_util_chajoin(rst, spl[*i][*j]);
		++(*j);
	}
	free(spl[*i]);
	spl[*i] = 0;
	spl[*i] = ft_util_strdup(rst);
	return (0);
}

void				ft_parse_semi(int *jdx, int *idx, t_par **par)
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
}

int					ft_parse_process_special
	(char **spl, t_par **par, int *idx, int *jdx)
{
	char			*rst;

//	printf("[[%s]]\n", spl[*idx]);
	if ((rst = (ft_util_strnstr(spl[*idx], "\"",
		ft_util_strlen(spl[*idx])))) != NULL)
		return (ft_parse_quotes_big(spl, idx, jdx));
	if ((rst = (ft_util_strnstr(spl[*idx], "\'",
		ft_util_strlen(spl[*idx])))) != NULL)
		return (ft_parse_quotes_sml(spl, idx, jdx));
	if ((rst = (ft_util_strnstr(spl[*idx], "$",
		ft_util_strlen(spl[*idx])))) != NULL)
		return (ft_parse_dollar(idx, spl));
	if ((rst = (ft_util_strnstr(spl[*idx], ";",
		ft_util_strlen(spl[*idx])))) != NULL)
	{
		(*par)->spl[*jdx] = NULL;
		(*par)->typ = TYPE_SEMI;
		ft_parse_semi(jdx, idx, par);
		return (1);
	}
	if ((rst = (ft_util_strnstr(spl[*idx], "|",
		ft_util_strlen(spl[*idx])))) != NULL)
	{
		(*par)->spl[*jdx] = NULL;
		(*par)->typ = TYPE_PIPE;
		ft_parse_semi(jdx, idx, par);
		return (1);
	}
	return (0);
}

t_par				*ft_parse_cmd(char *lin, t_par *par)
{
	int				idx;
	int				jdx;
	char			**spl;
	char			*tmp;

	idx = 0;
	if (!(tmp = ft_parse_space(lin, 0)))
		return (0);
	if (par == NULL)
		par = ft_util_parse_init();
	spl = ft_parse_split(tmp);
	free(tmp);
	while (spl[idx])
	{
		jdx = 0;
		// printf("[[%s]]\n", par->spl[idx]);
		if (ft_parse_process_special(spl, &par, &idx, &jdx) == 1)
			continue ;
		par->spl[idx] = ft_util_strdup(spl[idx]);
		++idx;
		++jdx;
	}
	par->spl[idx] = NULL;
	ft_util_parse_list_rewind(&par);
	ft_util_freestrstr(spl);
	return (par);
}
