/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_space_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:12:17 by juhpark           #+#    #+#             */
/*   Updated: 2021/05/07 03:19:30 by juhpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_mns				*g_mns;

int					tocken_semi(char *lin, char *ret, int *indx)
{
	if (*indx == 0 || ft_util_strlen(lin) == 1 ||
			lin[*indx + 1] == ';' || lin[*indx + 1] == '|' ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == ';') ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == '|'))
		return (0);
	if (lin[*indx - 1] != ' ')
		ret = ft_util_strjoin(ret, " ;");
	if (lin[*indx + 1] != ' ')
		ret = ft_util_chajoin(ret, ' ');
	return (1);
}

int					tocken_pipe(char *lin, char *ret, int *indx)
{
	if (*indx == 0 || ft_util_strlen(lin) == 1 ||
			lin[*indx + 1] == ';' || lin[*indx + 1] == '|' ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == ';') ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == '|') ||
			lin[*indx + 1] == '\0')
	{
		err_by_syntax(&g_mns->ext);
		return (0);
	}
	if (lin[*indx - 1] != ' ')
		ret = ft_util_strjoin(ret, " |");
	if (lin[*indx + 1] != ' ')
		ret = ft_util_chajoin(ret, ' ');
	return (1);
}

int					tocken_decresc(char *lin, char *ret, int *indx)
{
	if (*indx == 0 || ft_util_strlen(lin) == 1 || lin[*indx + 1] == '\0' ||
			lin[*indx + 1] == ';' || lin[*indx + 1] == '<' ||
			lin[*indx + 1] == '|' ||
			(lin[*indx + 1] == '>' && lin[*indx + 2] == '>') ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == ';') ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == '|') ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == '<') ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == '>'))
		return (0);
	if (lin[*indx - 1] != ' ' && lin[*indx - 1] != '>')
	{
		ret = ft_util_strjoin(ret, " >");
		if (lin[*indx + 1] == '>')
		{
			ret = ft_util_chajoin(ret, '>');
			*indx += 1;
		}
	}
	if (lin[*indx + 1] != ' ' && lin[*indx - 1] != '>')
		ret = ft_util_chajoin(ret, ' ');
	return (1);
}

int					tocken_cresc(char *lin, char *ret, int *indx)
{
	if (*indx == 0 || ft_util_strlen(lin) == 1 || lin[*indx + 1] == '\0' ||
			lin[*indx + 1] == ';' || lin[*indx + 1] == '<' ||
			lin[*indx + 1] == '|' || lin[*indx + 1] == '>' ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == '<') ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == ';') ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == '<') ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == '|'))
		return (0);
	if (lin[*indx - 1] != ' ')
	{
		ret = ft_util_chajoin(ret, ' ');
	}
	if (lin[*indx + 1] != ' ')
	{
		ret = ft_util_chajoin(ret, ' ');
	}
	return (1);
}

void				ft_parse_sp_op(char *lin, char *ret, int *i, t_quo *quo)
{
	if (lin[*i] == ';' && tocken_semi(lin, ret, i) == 0)
		quo->type = -1;
	else if (lin[*i] == '|' && tocken_pipe(lin, ret, i) == 0)
		quo->type = -1;
	else if (lin[*i] == '>' && tocken_decresc(lin, ret, i) == 0)
		quo->type = -1;
	else if (lin[*i] == '<' && tocken_cresc(lin, ret, i) == 0)
		quo->type = -1;
}
