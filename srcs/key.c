/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:46:58 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/07 07:10:29 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

char				*ft_key_back(int *col, int *row, char *lin, t_cap *cap)
{
	if (cap->p_col >= *col)
		return (lin);
	*col -= 1;
	tputs(tgoto(cap->cm, *col, *row), 1, ft_util_putchar);
	tputs(cap->dc, 1, ft_util_putchar);
	lin = ft_util_chaout(lin, g_mns->idx);
	g_mns->idx -= 1;
	return (lin);
}

void				ft_key_left(int *col, int *row, t_cap *cap)
{
	if (cap->p_col >= *col)
		return ;
	*col -= 1;
	g_mns->idx -= 1;
	tputs(tgoto(cap->cm, *col, *row), 1, ft_util_putchar);
}

void				ft_key_right(int *col, int *row, char *lin, t_cap *cap)
{
	if (ft_util_strlen(lin) <= g_mns->idx + 1)
		return ;
	*col += 1;
	g_mns->idx += 1;
	tputs(tgoto(cap->cm, *col, *row), 1, ft_util_putchar);
}

void				ft_key_up(int *col, int *row, char **lin, t_cap *cap)
{
	char			*txt;

	txt = ft_history_up();
	if (txt == NULL)
		return ;
	tputs(tgoto(cap->cm, cap->p_col, cap->p_row), 1, ft_util_putchar);
	tputs(cap->ce, 1, ft_util_putchar);
	ft_util_putstr_fd(txt, 1);
	*col = cap->p_col + ft_util_strlen(txt);
	g_mns->idx = -1 + ft_util_strlen(txt);
	tputs(tgoto(cap->cm, *col, *row), 1, ft_util_putchar);
	free(*lin);
	*lin = 0;
	*lin = ft_util_strdup(txt);
}

void				ft_key_down(int *col, int *row, char **lin, t_cap *cap)
{
	char			*txt;

	txt = ft_history_down();
	if (txt == NULL)
		txt = ft_util_strdup("");
	tputs(tgoto(cap->cm, cap->p_col, cap->p_row), 1, ft_util_putchar);
	tputs(cap->ce, 1, ft_util_putchar);
	ft_util_putstr_fd(txt, 1);
	*col = cap->p_col + ft_util_strlen(txt);
	g_mns->idx = -1 + ft_util_strlen(txt);
	tputs(tgoto(cap->cm, *col, *row), 1, ft_util_putchar);
	free(*lin);
	*lin = 0;
	*lin = ft_util_strdup(txt);
}
