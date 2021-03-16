/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:43:03 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/10/01 16:43:19 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*fnc)(void *))
{
	if (!lst || !fnc)
		return ;
	while (lst)
	{
		fnc(lst->content);
		lst = lst->next;
	}
}
