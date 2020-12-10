/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_sort_utils_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:27:59 by kyuki             #+#    #+#             */
/*   Updated: 2020/12/04 20:36:27 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

void		ft_swap(t_tab *tab, long int i, long int j)
{
	t_tab tmp;

	tmp = tab[j];
	tab[j] = tab[i];
	tab[i] = tmp;
}
