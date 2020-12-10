/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:02:56 by kyuki             #+#    #+#             */
/*   Updated: 2020/10/11 03:02:58 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n-- > 0)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			return ((unsigned char *)s);
		}
		s++;
	}
	return (NULL);
}
