/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:02:05 by kyuki             #+#    #+#             */
/*   Updated: 2020/10/11 03:02:08 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	itoa_negative_length(int *n_1, long *length)
{
	long	n;

	n = *n_1;
	if (n < 0)
	{
		n *= -1;
		*length += 1;
	}
	if (n == 0)
		*length += 1;
	while (n)
	{
		n = n / 10;
		*length += 1;
	}
	if (*n_1 < 0)
		return (1);
	return (0);
}

static void	ft_itoa_process(char *dest, long length, long n, long negative)
{
	dest[length] = '\0';
	if (negative)
	{
		dest[0] = '-';
		n *= -1;
	}
	while (length--)
	{
		if (negative && length == 0)
			break ;
		dest[length] = n % 10 + '0';
		n = n / 10;
	}
}

char		*ft_itoa(int n)
{
	char	*dest;
	long	negative;
	long	length;

	length = 0;
	negative = itoa_negative_length(&n, &length);
	if (!(dest = malloc(sizeof(char) * (length) + 1)))
		return (NULL);
	if (n == 0)
	{
		dest[0] = '0';
		dest[1] = '\0';
		return (dest);
	}
	ft_itoa_process(dest, length, n, negative);
	return (dest);
}
