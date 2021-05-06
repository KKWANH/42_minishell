// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   export.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/03/24 15:35:02 by kimkwanho         #+#    #+#             */
// /*   Updated: 2021/04/11 10:50:57 by kimkwanho        ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

int					ft_export_err(char *str)
{
	ft_util_putstr_fd(ANSI_RED "minishell: ", 2);
	ft_util_putstr_fd(ANSI_MAG "export: '", 2);
	ft_util_putstr_fd(ANSI_YEL, 2);
	ft_util_putstr_fd(str, 2);
	ft_util_putstr_fd(ANSI_MAG "': Not a valid identifier\n", 2);
	ft_util_putstr_fd(ANSI_RES, 2);
	return (0);
}

void				ft_export_print(void)
{
	t_env			*env;

	env = g_mns->env;
	while (env)
	{
		ft_util_putstr_fd(ANSI_GRE "declare -x " ANSI_RES, 1);
		ft_util_putstr_fd(env->nam, 1);
		ft_util_putstr_fd("=", 1);
		ft_util_putstr_fd(env->val, 1);
		ft_util_putstr_fd("\n", 1);
		if (env->nxt)
			env = env->nxt;
		else
			break ;
	}
}

int					ft_export_process(char **s, int *i, int *f)
{
	int				j;
	int				e;
	char			*n;
	char			*v;

	j = 0;
	e = 0;
	n = ft_util_strdup("");
	v = ft_util_strdup("");
	while (s[*i][j])
	{
		if (s[*i][j] == '=')
			e = 1;
		else if (ft_util_is_num(s[*i][j]) == 1)
		{
			if (e == 0 && j == 0)
				return (ft_export_err(s[(*i)++]));
			if (e == 0)
				n = ft_util_chajoin(n, s[*i][j]);
			if (e == 1)
				v = ft_util_chajoin(v, s[*i][j]);
		}
		else if (ft_util_is_alpha(s[*i][j]) == 1)
		{
			if (e == 0)
				n = ft_util_chajoin(n, s[*i][j]);
			if (e == 1)
				v = ft_util_chajoin(v, s[*i][j]);
		}
		else if (e == 1)
			ft_util_chajoin(v, s[*i][j]);
		++j;
	}
	ft_env_add_update(n, v);
	(*f) = 1;
	(*i) += 1;
	return (1);
}

void				ft_export_cmd(t_par *par)
{
	int				idx;
	int				flg;

	idx = 1;
	flg = 0;
	while (par->spl[idx])
	{
		ft_export_process(par->spl, &idx, &flg);
	}
	if (flg == 0)
		ft_export_print();
}