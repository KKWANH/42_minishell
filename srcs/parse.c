/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:33:06 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/05 16:17:26 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

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

int					ft_parse_quotes(int *idx, char **spl)
{
	int				stt;
	int				end;
	int				nm1; // : spl
	int				nm2; // : rst
	char			*rst;

	stt = 0;
	while (spl[*idx][stt] && spl[*idx][stt] != '\"')
		++stt;
	end = stt + 1;
	while (spl[*idx][end] && spl[*idx][end] != '\"')
		++end;
	rst = (char *)malloc(sizeof(char) * (end - stt + 1));
	nm1 = 0;
	nm2 = 0;
	while (nm1 < stt)
	{
		rst[nm2] = spl[*idx][nm1];
		++nm2;
		++nm1;
	}
	++nm1;
	while (nm1 < end)
	{
		rst[nm2] = spl[*idx][nm1];
		++nm2;
		++nm1;
	}
	rst[nm2] = '\0';
	free(spl[*idx]);
	spl[*idx] = 0;
	spl[*idx] = rst;
	return (0);
}

int					ft_parse_dollar(int *idx, char **spl)
{
	int				stt;
	int				num;
	char			*nam;
	char			*rst;
	char			*tmp;

	stt = 0;
	num = 0;
	while (spl[*idx][stt] && spl[*idx][stt] != '$')
		++stt;
	nam = (char *)malloc(sizeof(char) * (ft_util_strlen(spl[0]) - stt));
	while (num < ft_util_strlen(spl[0]) - stt)
	{
		nam[num] = spl[*idx][stt + 1 + num];
		++num;
	}
	if (stt == 0)
		rst = ft_util_env_search(nam);
	else
	{
		tmp = ft_util_env_search(nam);
		rst = (char *)malloc(sizeof(char) * (stt + ft_util_strlen(tmp) + 1));
		num = 0;
		while (num < stt)
		{
			rst[num] = spl[*idx][num];
			++num;
		}
		stt = 0;
		while (stt < ft_util_strlen(tmp))
		{
			rst[num + stt] = tmp[stt];
			++stt;
		}
		rst[num + stt] = '\0';
	}
	free(nam);
	free(spl[*idx]);
	spl[*idx] = 0;
	spl[*idx] = rst;
	return (0);
}

int					ft_parse_process_special
	(char **spl, t_par **par, int *idx, int *jdx)
{
	char			*rst;

	if ((rst = (ft_util_strnstr(spl[*idx], "\"",
		ft_util_strlen(spl[*idx])))) != NULL)
		return (ft_parse_quotes(idx, spl));
	else if ((rst = (ft_util_strnstr(spl[*idx], "$",
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
	else if ((rst = (ft_util_strnstr(spl[*idx], "|",
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

	idx = 0;
	jdx = 0;
	if (par == NULL)
		par = ft_util_parse_init();
	spl = ft_util_split(lin, ' ');
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
