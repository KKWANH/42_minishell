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

/*
** HOW TO PROCESS CHECKING FOR LINE
**	while loop
**	 0. if [ ] : skip
**	 1. if ["] or ['] : get str.
**	  1.0. if doesn't close with ["] or ['] : return -1
**	 2. if str(name) doesn't have mate;str(value) : ignore it
**	 3. if [$] : get all alpha until another character comes, process it to str
**	 4. if 
*/

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

int					ft_export_process(char **spl, int *idx, int *flg)
{
	int				jdx;
	int				wht;
	char			*nam;
	char			*val;

	jdx = 0;
	wht = 1;
	nam = ft_util_strdup("");
	val = ft_util_strdup("");
	while (spl[(*idx)][jdx])
	{
		if (ft_util_is_alpha(spl[*idx][jdx]) == 1)
		{
			if (wht == 1)
				nam = ft_util_chajoin(nam, spl[*idx][jdx]);
			else
				val = ft_util_chajoin(val, spl[*idx][jdx]);
		}
		else
		{
			if (spl[*idx][jdx] == '=')
				wht = 2;
			else
				return (ft_export_err(spl[*idx]));
		}
		++jdx;
	}
	ft_env_add_update(nam, val);
	(*flg) = 1;
	++(*idx);
	return (0);
}

void				ft_export_cmd(t_par *par)
{
	int				flg;
	int				idx;

	flg = 0;
	idx = 1;
	while (par->spl[idx])
	{
		if (par->spl[idx][0] == '=')
		{
			ft_export_err(par->spl[idx++]);
			continue ;
		}
		ft_export_process(par->spl, &idx, &flg);
	}
	if (flg == 0)
		ft_export_print();

}