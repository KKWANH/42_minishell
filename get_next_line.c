/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhpark <juhpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:18:22 by juhpark           #+#    #+#             */
/*   Updated: 2021/03/15 14:15:27 by pjh399           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_gae_haeng(char *output)
{
	int i;

	i = 0;
	if (!output)
		return (-42);
	while (output[i])
	{
		if (output[i] == '\n')
			return (i);
		i++;
	}
	return (-4);
}

int	get_line(char **line, char **output, int indx)
{
	char *em_shi;

	(*output)[indx] = '\0';
	*line = ft_strdup(*output);
	em_shi = *output;
	*output = ft_strdup(*output + indx + 1);
	free(em_shi);
	return (1);
}

int	end_of_file(char **output, char **line, int indx)
{
	indx = find_gae_haeng(*output);
	if (*output && indx >= 0)
		return (get_line(line, output, indx));
	else if (*output)
	{
		*line = ft_strdup(*output);
		free(*output);
		*output = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char			buf[31];
	static char		*output[FOPEN_MAX];
	int				read_buf;
	int				indx;

	if (fd < 0 || line == 0)
		return (-1);
	while ((read_buf = read(fd, buf, 30)) > 0)
	{
		buf[read_buf] = '\0';
		if (output[fd] == NULL)
			output[fd] = ft_strdup(buf);
		else
			output[fd] = ft_strjoin(output[fd], buf);
		if ((indx = find_gae_haeng(output[fd])) >= 0)
			return (get_line(line, &output[fd], indx));
	}
	if (read_buf < 0)
		return (-1);
	return (end_of_file(&output[fd], line, indx));
}
