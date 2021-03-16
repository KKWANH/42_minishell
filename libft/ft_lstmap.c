/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:45:12 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/10/03 18:00:29 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*fnc)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *tmp;
	t_list *cur;

	new = ft_lstnew(fnc(lst->content));
	if (!lst || !new)
		return (NULL);
	cur = new;
	tmp = lst->next;
	while (tmp)
	{
		if (!(cur->next = ft_lstnew(fnc(tmp->content))))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		cur = cur->next;
		tmp = tmp->next;
	}
	return (new);
}
