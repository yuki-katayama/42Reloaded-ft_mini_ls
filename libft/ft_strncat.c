/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 01:26:28 by kyuki             #+#    #+#             */
/*   Updated: 2020/09/27 01:26:32 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t dest_len;
	size_t i;

	dest_len = 0;
	while (s1[dest_len])
		dest_len++;
	i = 0;
	while (i < n && s2[i])
	{
		s1[dest_len + i] = s2[i];
		i++;
	}
	s1[dest_len + i] = '\0';
	return (s1);
}
