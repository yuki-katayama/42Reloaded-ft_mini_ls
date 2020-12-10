/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:02:31 by kyuki             #+#    #+#             */
/*   Updated: 2020/10/11 03:02:32 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*m;
	t_list	*la;

	if (!lst)
		return (NULL);
	m = lst;
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	la = lst;
	lst = m;
	return (la);
}
