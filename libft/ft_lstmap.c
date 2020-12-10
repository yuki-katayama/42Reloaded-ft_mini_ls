/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:02:38 by kyuki             #+#    #+#             */
/*   Updated: 2020/10/11 03:02:40 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;
	t_list *elem;

	if (!lst)
		return (NULL);
	if (!(new_list = ft_lstnew(f(lst->content))))
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		if (!(elem = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, elem);
		lst = lst->next;
	}
	return (new_list);
}
