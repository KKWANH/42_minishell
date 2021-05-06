/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_space_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:12:17 by juhpark           #+#    #+#             */
/*   Updated: 2021/05/06 16:25:27 by juhpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_mns			*g_mns;

int				tocken_semi(char *lin, int *ret, int indx)
{
	if (indx == 0 || ft_util_strlen(lin) == 1 ||
			lin[indx + 1] == ';' || lin[indx + 1] == '|' ||
			(lin[indx + 1] == ' ' && lin[indx + 2] == ';') ||
			(lin[indx + 1] == ' ' && lin[indx + 2] == '|'))
	{
		err_by_syntax(&g_mns->ext);
		return (0);
	}
	if (lin[indx - 1] != ' ')
		*ret += 1;
	if (lin[indx + 1] != ' ')
		*ret += 1;
	return (1);
}

int				tocken_pipe(char *lin, int *ret, int indx)
{
	if (indx == 0 || ft_util_strlen(lin) == 1 ||
			lin[indx + 1] == ';' || lin[indx + 1] == '|' ||
			(lin[indx + 1] == ' ' && lin[indx + 2] == ';') ||
			(lin[indx + 1] == ' ' && lin[indx + 2] == '|') ||
			lin[indx + 1] == '\0')
	{
		err_by_syntax(&g_mns->ext);
		return (0);
	}
	if (lin[indx - 1] != ' ')
		*ret += 1;
	if (lin[indx + 1] != ' ')
		*ret += 1;
	return (1);
}

int				tocken_decresc(char *lin, int *ret, int indx)
{
	if (indx == 0 || ft_util_strlen(lin) == 1 || lin[indx + 1] == '\0' ||
			lin[indx + 1] == ';' || lin[indx + 1] == '<' ||
			lin[indx + 1] == '|' ||
			(lin[indx + 1] == '>' && lin[indx + 2] == '>') ||
			(lin[indx + 1] == ' ' && lin[indx + 2] == ';') ||
			(lin[indx + 1] == ' ' && lin[indx + 2] == '|') ||
			(lin[indx + 1] == ' ' && lin[indx + 2] == '<') ||
			(lin[indx + 1] == ' ' && lin[indx + 2] == '>'))
	{
		err_by_syntax(&g_mns->ext);
		return (0);
	}
	if (lin[indx - 1] != ' ' && lin[indx - 1] != '>')
		*ret += 1;
	if (lin[indx + 1] != ' ' && lin[indx - 1] != '>')
		*ret += 1;
	return (1);
}

int				tocken_cresc(char *lin, int *ret, int indx)
{
	if (indx == 0 || ft_util_strlen(lin) == 1 || lin[indx + 1] == '\0' ||
			lin[indx + 1] == ';' || lin[indx + 1] == '<' ||
			lin[indx + 1] == '|' || lin[indx + 1] == '>' ||
			(lin[indx + 1] == ' ' && lin[indx + 2] == '<') ||
			(lin[indx + 1] == ' ' && lin[indx + 2] == ';') ||
			(lin[indx + 1] == ' ' && lin[indx + 2] == '<') ||
			(lin[indx + 1] == ' ' && lin[indx + 2] == '|'))
	{
		err_by_syntax(&g_mns->ext);
		return (0);
	}
	if (lin[indx - 1] != ' ')
		*ret += 1;
	if (lin[indx + 1] != ' ')
		*ret += 1;
	return (1);
}

int				ft_count_sp_token(char *lin)
{
	int			ret;
	int			i;

	ret = 0;
	i = 0;
	while (lin[i])
	{
		if (lin[i] == ';' && tocken_semi(lin, &ret, i) == 0)
			return (-1);
		else if (lin[i] == '|' && tocken_pipe(lin, &ret, i) == 0)
			return (-1);
		else if (lin[i] == '>' && tocken_decresc(lin, &ret, i) == 0)
			return (-1);
		else if (lin[i] == '<' && tocken_cresc(lin, &ret, i) == 0)
			return (-1);
		i++;
	}
	return (ret);
}
