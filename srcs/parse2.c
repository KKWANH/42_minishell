/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:33:06 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/22 16:08:59 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

char				*ft_parse_get_str(char *lin, int *idx)
{
	int				cnt;
	int				jdx;
	char			*str;

	cnt = *idx;
	jdx = 0;
	while (lin[cnt] && ft_util_is_empty(lin[cnt]) == 0)
		++cnt;
	cnt = cnt - *idx;
	str = (char *)malloc(sizeof(char) * (cnt + 1));
	while (jdx < cnt)
	{
		str[jdx] = lin[*idx + jdx];
		++jdx;
	}
	str[jdx] = '\0';
	*idx += cnt;
	return (str);
}

void				ft_parse_cmd_cut(t_cmd *cmd)
{
	int				idx;
	t_str			*new;

	idx = 0;
	new = (t_str *)malloc(sizeof(t_str));
	new->str = NULL;
	new->nxt = NULL;
	while (cmd->lin[idx])
	{
		if (ft_util_is_empty(cmd->lin[idx]) == 1)
			++idx;
		else
			ft_util_str_lstaddback(&new, ft_parse_get_str(cmd->lin, &idx));
	}
	cmd->spl = new;
}

int					ft_parse_cmd(char *lin)
{
	t_cmd			*cmd;
	int				idx;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->lin = lin;
	cmd->pre = NULL;
	cmd->nxt = NULL;
	idx = 0;
	// while (cmd->lin[idx])
	// {
	// 	if (ft_util_is_empty(cmd->lin[idx]))
	// 		++idx;
	// 	else if (cmd->lin[idx] == '$')
	// 		ft_parse_dollar(lin, &idx, cmd);
	// 	else if (cmd->lin[idx] == '\"')
	// 		ft_parse_double_quote(lin, &idx, cmd);
	// 	else if (cmd->lin[idx] == '\'')
	// 		ft_parse_single_quote(lin, &idx, cmd);
	// }
	ft_parse_cmd_cut(cmd);
	ft_util_cmd_lstaddback(cmd);
	return (1);
}