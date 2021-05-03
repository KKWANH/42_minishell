/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:33:06 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/03 17:30:11 by juhpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

int					ft_parse_list_rewind(t_par **par)
{
	while (*par && (*par)->pre)
		*par = (*par)->pre;
	return (0);
}

int					ft_parse_list_free(t_par **par)
{
	t_par			*tmp;
	int				idx;

	ft_parse_list_rewind(par);
	while (*par)
	{
		idx = 0;
		tmp = (*par)->nxt;
		if ((*par)->spl != NULL)
			ft_util_freestrstr((*par)->spl);
		free(*par);
		*par = tmp;
	}
	return (0);
}

t_par				*ft_parse_init(void)
{
	t_par			*new;

	if (!(new = (t_par *)malloc(sizeof(t_par))))
		return (NULL);
	new->spl = (char **)malloc(sizeof(char *) * 100);
	new->pip = 0;
	new->typ = 0;
	new->nxt = NULL;
	new->pre = NULL;
	new->fd_in = -2;
	new->fd_out = -2;
	return (new);
}

void					ft_parse_semi(int *jdx, int *idx, t_par **par)
{
	t_par *new;

	*jdx = 0;
	*idx += 1;
	new = ft_parse_init();
	if (*par)
	{
		(*par)->nxt = new;
		new->pre = (*par);
	}
	*par = new;
}

t_par				*ft_parse_cmd(char *lin, t_par *par)
{
	int				idx;
	int				jdx;
	char			**spl;
	char			*rst;

	idx = 0;
	jdx = 0;
	if (par == NULL)
		par = ft_parse_init();
	spl = ft_util_split(lin, ' ');
	while (spl[idx])
	{
		if ((rst = (ft_util_strnstr(spl[idx], ";", ft_util_strlen(spl[idx])))) != NULL)
		{
			par->spl[jdx] = NULL;
			par->typ = TYPE_SEMI;
			ft_parse_semi(&jdx, &idx, &par);
			continue ;
		}
		else if ((rst = (ft_util_strnstr(spl[idx], "|", ft_util_strlen(spl[idx])))) != NULL)
		{
			par->spl[jdx] = NULL;
			par->typ = TYPE_PIPE;
			ft_parse_semi(&jdx, &idx, &par);
			continue ;
		}
		par->spl[jdx] = ft_util_strdup(spl[idx]);
		++idx;
		++jdx;
	}
	par->spl[jdx] = NULL;
	ft_parse_list_rewind(&par);
	ft_util_freestrstr(spl);
	return (par);
}
