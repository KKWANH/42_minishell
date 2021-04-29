/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:33:06 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/04/29 23:53:37 by kimkwanho        ###   ########.fr       */
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

int					ft_parse_cmd_cut(t_cmd *cmd)
{
	int				idx;
	int				jdx;

	idx = 0;
	jdx = 0;
	while (cmd->lin[idx])
	{
		while (cmd->lin[idx] && ft_util_is_empty(cmd->lin[idx]) == 1)
			++idx;
		if (cmd->lin[idx] && ft_util_is_empty(cmd->lin[idx]) == 0)
			++jdx;
		while (cmd->lin[idx] && ft_util_is_empty(cmd->lin[idx]) == 0)
			++idx;
	}
	idx = 0;
	if (!(cmd->spl = (char **)malloc(sizeof(char *) * (jdx + 1))))
		return (0);
	jdx = 0;
	while (cmd->lin[idx])
	{
		if (ft_util_is_empty(cmd->lin[idx]) == 1)
			++idx;
		else
		{
			cmd->spl[jdx] = ft_parse_get_str(cmd->lin, &idx);
			++jdx;
		}
	}
	cmd->spl[jdx] = NULL;
	return (1);
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
	if (ft_parse_cmd_cut(cmd) == 0)
		return (0);
	ft_util_cmd_lstaddback(cmd);
	return (1);
}