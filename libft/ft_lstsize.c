/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:02:46 by kyuki             #+#    #+#             */
/*   Updated: 2020/10/11 03:02:49 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*m;
	int		count;

	count = 0;
	m = lst;
	while (lst != NULL)
	{
		count += 1;
		lst = lst->next;
	}
	lst = m;
	return (count);
}
