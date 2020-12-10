/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:10:41 by kyuki             #+#    #+#             */
/*   Updated: 2020/10/11 03:10:42 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s1;
	size_t	length;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (!(s1 = malloc(sizeof(char) * length + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		s1[i] = (*f)(i, s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
