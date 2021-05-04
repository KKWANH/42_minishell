/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:00:44 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/04 10:02:05 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

int					ft_util_parse_list_rewind(t_par **par)
{
	while (*par && (*par)->pre)
		*par = (*par)->pre;
	return (0);
}

int					ft_util_parse_list_free(t_par **par)
{
	t_par			*tmp;
	int				idx;

	ft_util_parse_list_rewind(par);
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

t_par				*ft_util_parse_init(void)
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