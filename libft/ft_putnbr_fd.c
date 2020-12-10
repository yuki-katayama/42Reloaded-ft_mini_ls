/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:05:20 by kyuki             #+#    #+#             */
/*   Updated: 2020/10/11 03:05:22 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char	c;
	long	a;

	a = nb;
	if (a < 0)
	{
		write(fd, "-", 1);
		a = a * -1;
	}
	if (a >= 10)
	{
		ft_putnbr_fd((int)(a / 10), fd);
		ft_putnbr_fd((int)(a % 10), fd);
	}
	else
	{
		c = a + '0';
		write(fd, &c, 1);
	}
}
