/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 08:54:33 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/05/03 23:32:21 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mns				*g_mns;

char				*ft_minishell_insert
	(char chr, int *col, int *row, t_cap *cap)
{
	int				c_col;

	c_col = *col - g_mns->cap.p_col;
	g_mns->test = c_col;
	if (ft_util_strlen(g_mns->lin) == 0 && g_mns->idx < 0)
		return (g_mns->lin);
	tputs(tgoto(cap->cm, *col, *row), 1, ft_util_putchar);
	tputs(cap->ce, 1, ft_util_putchar);
	g_mns->lin = ft_util_addcha(g_mns->lin, chr, c_col);
	g_mns->idx += 1;
	ft_util_putstr_fd(&g_mns->lin[c_col], 1);
	*col += 1;
	tputs(tgoto(cap->cm, *col, *row), 1, ft_util_putchar);
	return (g_mns->lin);
}

void				ft_minishell_input_main(int col, int row, int tmp)
{
	char			chr;
	int				rst;

	g_mns->test = 0;
	while (read(0, &tmp, sizeof(tmp)) > 0)
	{
		rst = ft_cursor(&col, &row, tmp);
		if (rst == -1)
		{
			ft_history_set_zero();
			return ;
		}
		if (rst == 0)
		{
			chr = tmp;
			if (chr < 32 || tmp > 127)
				tmp = 0;
			else if (g_mns->idx + 1 != ft_util_strlen(g_mns->lin))
				g_mns->lin = ft_minishell_insert(chr, &col, &row, &g_mns->cap);
			else
			{
				write(0, &tmp, 1);
				g_mns->lin = ft_util_chajoin(g_mns->lin, chr);
				++g_mns->idx;
			}
		}
		tmp = 0;
	}
}

int					main(int arc, char **arv, char **env)
{
	struct termios	s_term;
	struct termios	s_backup;

	if (!(g_mns = (t_mns *)malloc(sizeof(t_mns))))
		return (-1);
	ft_init(env, &s_term, &s_backup);
	while (1)
	{
		ft_prompt_put_msg();
		tcsetattr(STDIN_FILENO, TCSANOW, &s_term);
		ft_cursor_whereisit(&g_mns->cap.p_col, &g_mns->cap.p_row);
		g_mns->lin = ft_util_strdup("");
		ft_minishell_input_main(0, 0, 0);
		tcsetattr(STDIN_FILENO, TCSANOW, &s_backup);
		ft_exe(g_mns->lin);
		free(g_mns->lin);
	}
	return (0);
}
