/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:10:59 by kyuki             #+#    #+#             */
/*   Updated: 2020/10/11 03:11:01 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t length;

	length = ft_strlen(s) + 1;
	while (length-- > 0)
	{
		if (((unsigned char *)s)[length] == (unsigned char)c)
		{
			return (&((char *)s)[length]);
		}
	}
	return (NULL);
}
