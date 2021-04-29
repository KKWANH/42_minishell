/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:44:14 by juhpark           #+#    #+#             */
/*   Updated: 2021/04/29 23:37:17 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_mns		*g_mns;

void				err_by_exit(char *arg, unsigned char *ext)
{
	ft_util_putstr_fd(ANSI_RED, 2);
	ft_util_putstr_fd("minishell: exit: ", 2);
	ft_util_putstr_fd(arg, 2);
	ft_util_putstr_fd(": numeric argument required\n", 2);
	ft_util_putstr_fd(ANSI_RES, 2);
	*ext = 127;
	exit(127);
}

void				err_by_chdir(char *arg, unsigned char *ext)
{
	ft_util_putstr_fd(ANSI_RED, 2);
	ft_util_putstr_fd("cd: ", 2);
	ft_util_putstr_fd("no such file or directory: \n", 2);
	ft_util_putstr_fd(arg, 2);
	ft_util_putstr_fd(ANSI_RES, 2);
	*ext = 1;
}

void				err_by_command(char *par, unsigned char *ext)
{
	ft_util_putstr_fd(ANSI_RED, 2);
	ft_util_putstr_fd("minishell: ", 2);
	ft_util_putstr_fd(par, 2);
	ft_util_putstr_fd(": command not found\n", 2);
	ft_util_putstr_fd(ANSI_RES, 2);
	*ext = 127;
	exit(127);
}

void				err_by_path(char *par, unsigned char *ext)
{
	ft_util_putstr_fd(ANSI_RED, 2);
	ft_util_putstr_fd("minishell: ", 2);
	ft_util_putstr_fd(par, 2);
	ft_util_putstr_fd(": No such file or directory\n", 2);
	ft_util_putstr_fd(ANSI_RES, 2);
	*ext = 127;
}

void				err_by_pid(unsigned char *ext)
{
	ft_util_putstr_fd(ANSI_RED, 2);
	ft_util_putstr_fd("pid error\n", 2);
	ft_util_putstr_fd(ANSI_RES, 2);
	*ext = 1;
//	exit(1);
}
