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

/*
** HOW TO PROCESS COMMAND [EXPORT] by kkim
**	0. Check that argument is empty
**	 0.0. if that so - sort env and put to command like [declare -x NAME="VALUE"]
**	1. Make list of argument. Of course seperate them to NAME and VALUE.
*/
void				ft_export_cmd(t_par *par)
{
	int				flg;
	int				idx;

	flg = 0;
	idx = 0;
	if (!par)
		printf("");
	// while (par->spl[idx])
	// {
	// 	// if (ft_export_process(par->spl, &idx) == 1)
	// 	// 	flg = 1;
	// 	++idx;
	// }
	if (flg == 0)
		ft_export_print();

}