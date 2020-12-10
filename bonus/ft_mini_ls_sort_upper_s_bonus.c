/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_sort_upper_s_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:28:22 by kyuki             #+#    #+#             */
/*   Updated: 2020/12/04 20:44:21 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

static void		ft_sort_upper_s_name(t_tab *tab, unsigned long int len,
									unsigned long int i, unsigned long int j)
{
	long long	max;

	max = tab[i].file_size;
	while (j < len && (tab[i].file_size == tab[j].file_size))
	{
		if (ft_strcmp(tab[i].s, tab[j].s) > 0)
			ft_swap(tab, i, j);
		j++;
	}
}

void			ft_sort_by_flag_upper_s(t_tab *tab, unsigned long int len)
{
	unsigned long int		i;
	unsigned long int		j;
	time_t					max;

	j = 0;
	i = 0;
	while (i < len - 1)
	{
		max = tab[i].file_size;
		j = i + 1;
		while (j < len)
		{
			if (max < tab[j].file_size)
			{
				max = tab[j].file_size;
				ft_swap(tab, i, j);
			}
			else if (tab[j].file_size == tab[i].file_size)
				ft_sort_upper_s_name(tab, len, i, j);
			j++;
		}
		i++;
	}
}
