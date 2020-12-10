/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:02:42 by kyuki             #+#    #+#             */
/*   Updated: 2020/10/11 03:02:44 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *a;

	a = NULL;
	if (!(a = malloc(sizeof(t_list))))
		return (NULL);
	a->content = (char *)content;
	a->next = NULL;
	return (a);
}
