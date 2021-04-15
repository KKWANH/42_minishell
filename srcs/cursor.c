/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:40:42 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/15 11:46:40 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

void				ft_cursor_whereisit(int *col, int *row)
{
	char			buf[100];
	int				ret;
	int				idx;

	*col = -1;
	*row = -1;
	write(0, "\e[6n", 4);
	ret = read(0, buf, 99);
	buf[ret] = '\0';
	idx = 0;
	while (buf[idx])
	{
		if (ft_util_is_num(buf[idx]) == 1)
		{
			if (*row < 0)
				*row = ft_util_atoi(&buf[idx]) - 1;
			else
				*col = ft_util_atoi(&buf[idx]) - 1;
			while (ft_util_is_num(buf[idx]) == 1)
				++idx;
		}
		++idx;
	}
}

void				ft_cursor_read_eof(char *lin)
{
	ft_util_putstr_fd("  \b\b", 1);
	if (ft_util_strlen(lin) != 0)
		g_mns->tmp = lin;
	if (ft_util_strlen(g_mns->tmp) == 0)
	{
		printf("exit\n");
		exit(0);
	}
}

int					ft_cursor(int *col, int *row, int tmp)
{
	ft_cursor_whereisit(col, row);
	if (tmp == LEFT_ARROW)
		ft_key_left(col, row, &g_mns->cap);
	else if (tmp == RIGHT_ARROW)
		ft_key_right(col, row, g_mns->lin, &g_mns->cap);
	else if  (tmp == UP_ARROW)
		write(1, "up", 2);
	else if (tmp == DOWN_ARROW)
		write(1, "down", 4);
	else if (tmp == BACKSPACE)
		g_mns->lin = ft_key_backspace(col, row, g_mns->lin, &g_mns->cap);
	else if (tmp == CTRL_D)
		ft_cursor_read_eof(g_mns->lin);
	else if (tmp == ENTER)
	{
		write(1, "\n", 1);
		return (-1);
		g_mns->idx = -1;
	}
	else
		return (0);
	return (1);
}