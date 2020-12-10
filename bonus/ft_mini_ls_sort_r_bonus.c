/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_sort_r_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:30:22 by kyuki             #+#    #+#             */
/*   Updated: 2020/12/04 20:35:59 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

void			ft_sort_rev(t_tab *tab, long int len)
{
	long int	i;
	long int	j;

	i = 0;
	j = len - 1;
	while (i < len / 2)
	{
		ft_swap(tab, i, j);
		i++;
		j--;
	}
}
