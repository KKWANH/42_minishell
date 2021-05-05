/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:44:14 by juhpark           #+#    #+#             */
/*   Updated: 2021/05/05 21:58:27 by juhpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

void				err_by_exit(char *arg, int *ext)
{
	ft_util_putstr_fd(ANSI_RED "minishell: ", 2);
	ft_util_putstr_fd(ANSI_MAG "cd: ", 2);
	ft_util_putstr_fd(ANSI_YEL, 2);
	ft_util_putstr_fd(arg, 2);
	ft_util_putstr_fd(ANSI_MAG ": Numeric argument required\n", 2);
	ft_util_putstr_fd(ANSI_RES, 2);
	*ext = 255;
	exit(255);
}

void				err_by_chdir(char *arg, int *ext)
{
	ft_util_putstr_fd(ANSI_RED "minishell: ", 2);
	ft_util_putstr_fd(ANSI_MAG "cd: ", 2);
	ft_util_putstr_fd(ANSI_YEL, 2);
	ft_util_putstr_fd(arg, 2);
	ft_util_putstr_fd(ANSI_MAG ": No such file or directory\n", 2);
	ft_util_putstr_fd(ANSI_RES, 2);
	*ext = 1;
}

void				err_by_command(char *par, int *ext)
{
	ft_util_putstr_fd(ANSI_RED "minishell: ", 2);
	ft_util_putstr_fd(ANSI_YEL, 2);
	ft_util_putstr_fd(par, 2);
	ft_util_putstr_fd(ANSI_MAG ": Command not found\n", 2);
	ft_util_putstr_fd(ANSI_RES, 2);
	*ext = 127;
	exit(127);
}

void				err_by_path(char *par, int *ext)
{
	ft_util_putstr_fd(ANSI_RED "minishell: ", 2);
	ft_util_putstr_fd(ANSI_YEL, 2);
	ft_util_putstr_fd(par, 2);
	ft_util_putstr_fd(ANSI_MAG ": No such file or directory\n", 2);
	ft_util_putstr_fd(ANSI_RES, 2);
	*ext = 127;
	exit(127);
}

void				err_by(char *msg, int *ext)
{
	ft_util_putstr_fd(ANSI_RED, 2);
	ft_util_putstr_fd(msg, 2);
	ft_util_putstr_fd(ANSI_RES, 2);
	*ext = 1;
}
