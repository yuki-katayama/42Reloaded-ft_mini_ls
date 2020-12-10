/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_sort_t_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:28:19 by kyuki             #+#    #+#             */
/*   Updated: 2020/12/04 20:35:56 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

static void		ft_sort_nsec_name(t_tab *tab, unsigned long int len,
								unsigned long int i, unsigned long int j)
{
	time_t max;

	max = tab[i].n_time;
	while (j < len && (tab[i].m_time == tab[j].m_time))
	{
		if (max < tab[j].n_time)
		{
			max = tab[j].n_time;
			ft_swap(tab, i, j);
		}
		else if (ft_strcmp(tab[i].s, tab[j].s) > 0 &&
				(tab[i].n_time == tab[j].n_time))
			ft_swap(tab, i, j);
		j++;
	}
}

void			ft_sort_by_flag_t(t_tab *tab, unsigned long int len)
{
	unsigned long int		i;
	unsigned long int		j;
	time_t					max;

	j = 0;
	i = 0;
	while (i < len - 1)
	{
		max = tab[i].m_time;
		j = i + 1;
		while (j < len)
		{
			if (max < tab[j].m_time)
			{
				max = tab[j].m_time;
				ft_swap(tab, i, j);
			}
			else if (tab[j].m_time == tab[i].m_time)
				ft_sort_nsec_name(tab, len, i, j);
			j++;
		}
		i++;
	}
}
