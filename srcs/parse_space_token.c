/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_space_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:12:17 by juhpark           #+#    #+#             */
/*   Updated: 2021/05/07 07:09:25 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_mns				*g_mns;

char				*tocken_semi(char *lin, char *ret, int *indx, t_quo *quo)
{
	if (*indx == 0 || ft_util_strlen(lin) == 1 ||
			lin[*indx + 1] == ';' || lin[*indx + 1] == '|' ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == ';') ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == '|'))
	{
		quo->type = -1;
		return (ret);
	}
	if (lin[*indx - 1] != ' ')
		ret = ft_util_chajoin(ret, ' ');
	ret = ft_util_chajoin(ret, ';');
	if (lin[*indx + 1] != ' ')
		ret = ft_util_chajoin(ret, ' ');
	return (ret);
}

char				*tocken_pipe(char *lin, char *ret, int *indx, t_quo *quo)
{
	if (*indx == 0 || ft_util_strlen(lin) == 1 ||
			lin[*indx + 1] == ';' || lin[*indx + 1] == '|' ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == ';') ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == '|') ||
			lin[*indx + 1] == '\0')
	{
		quo->type = -1;
		return (ret);
	}
	if (lin[*indx - 1] != ' ')
		ret = ft_util_chajoin(ret, ' ');
	ret = ft_util_chajoin(ret, '|');
	if (lin[*indx + 1] != ' ')
		ret = ft_util_chajoin(ret, ' ');
	return (ret);
}

char				*tocken_decresc(char *lin, char *ret, int *indx, t_quo *quo)
{
	if (*indx == 0 || ft_util_strlen(lin) == 1 || lin[*indx + 1] == '\0' ||
			lin[*indx + 1] == ';' || lin[*indx + 1] == '<' ||
			lin[*indx + 1] == '|' ||
			(lin[*indx + 1] == '>' && lin[*indx + 2] == '>') ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == ';') ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == '|') ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == '<') ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == '>'))
	{
		quo->type = -1;
		return (ret);
	}
	if (lin[*indx - 1] != ' ' && lin[*indx - 1] != '>')
		ret = ft_util_chajoin(ret, ' ');
	ret = ft_util_chajoin(ret, '>');
	if (lin[*indx + 1] == '>')
	{
		ret = ft_util_chajoin(ret, '>');
		*indx += 1;
	}
	if (lin[*indx + 1] != ' ' && lin[*indx + 1] != '>')
		ret = ft_util_chajoin(ret, ' ');
	return (ret);
}

char				*tocken_cresc(char *lin, char *ret, int *indx, t_quo *quo)
{
	if (*indx == 0 || ft_util_strlen(lin) == 1 || lin[*indx + 1] == '\0' ||
			lin[*indx + 1] == ';' || lin[*indx + 1] == '<' ||
			lin[*indx + 1] == '|' || lin[*indx + 1] == '>' ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == '<') ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == ';') ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == '<') ||
			(lin[*indx + 1] == ' ' && lin[*indx + 2] == '|'))
	{
		quo->type = -1;
		return (ret);
	}
	if (lin[*indx - 1] != ' ')
		ret = ft_util_chajoin(ret, ' ');
	ret = ft_util_chajoin(ret, '<');
	if (lin[*indx + 1] != ' ')
		ret = ft_util_chajoin(ret, ' ');
	return (ret);
}

char				*ft_parse_sp_op(char *lin, char *ret, int *i, t_quo *quo)
{
	if (lin[*i] == ';')
		ret = tocken_semi(lin, ret, i, quo);
	else if (lin[*i] == '|')
		ret = tocken_pipe(lin, ret, i, quo);
	else if (lin[*i] == '>')
		ret = tocken_decresc(lin, ret, i, quo);
	else if (lin[*i] == '<')
		ret = tocken_cresc(lin, ret, i, quo);
	return (ret);
}
