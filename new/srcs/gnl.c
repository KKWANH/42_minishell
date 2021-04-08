/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 08:32:30 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/03/24 08:39:21 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int					ft_gnl_is_nl(char *out)
{
	int				i;

	i = 0;
	if (!out)
		return (-42);
	while (out[i])
	{
		if (out[i] == '\n')
			return (i);
		i++;
	}
	return (-4);
}

int					ft_gnl_get_line(char **lin, char **out, int idx)
{
	char *tmp;

	(*out)[idx] = '\0';
	*lin = ft_util_strdup(*out);
	tmp = *out;
	*out = ft_util_strdup(*out + idx + 1);
	free(tmp);
	return (1);
}

int					ft_gnl_eof(char **out, char **lin, int idx)
{
	idx = ft_gnl_is_nl(*out);
	if (*out && idx >= 0)
		return (ft_gnl_get_line(lin, out, idx));
	else if (*out)
	{
		*lin = ft_util_strdup(*out);
		free(*out);
		*out = 0;
		return (0);
	}
	*lin = ft_util_strdup("");
	return (0);
}

int					get_next_line(int fil, char **lin)
{
	char			buf[31];
	static char		*out[FOPEN_MAX];
	int				read_buf;
	int				idx;

	if (fil < 0 || lin == 0)
		return (-1);
	while ((read_buf = read(fil, buf, 30)) > 0)
	{
		buf[read_buf] = '\0';
		if (out[fil] == NULL)
			out[fil] = ft_util_strdup(buf);
		else
			out[fil] = ft_util_strjoin(out[fil], buf);
		if ((idx = ft_gnl_is_nl(out[fil])) >= 0)
			return (ft_gnl_get_line(lin, &out[fil], idx));
	}
	if (read_buf < 0)
		return (-1);
	return (ft_gnl_eof(&out[fil], lin, idx));
}
