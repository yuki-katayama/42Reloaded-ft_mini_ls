/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:02:59 by kyuki             #+#    #+#             */
/*   Updated: 2020/10/11 03:03:01 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;

	i = 0;
	while (n-- > 0)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		i++;
	}
	return (0);
}
