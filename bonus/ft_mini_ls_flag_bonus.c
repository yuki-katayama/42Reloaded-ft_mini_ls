/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_flag_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:58:30 by kyuki             #+#    #+#             */
/*   Updated: 2020/12/04 23:53:20 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

void	ft_process_start(t_tab *tab, t_info info)
{
	if (ft_strchr_kai(info.flag, 'S'))
		ft_sort_by_flag_upper_s(tab, info.sumpath);
	else if (ft_strchr_kai(info.flag, 't'))
		ft_sort_by_flag_t(tab, info.sumpath);
	if (ft_strchr_kai(info.flag, 'r'))
		ft_sort_rev(tab, info.sumpath);
	if (ft_strchr_kai(info.flag, 's') && !ft_strchr_kai(info.flag, 'm'))
	{
		write(1, "total ", 6);
		ft_putnbr_write_len(info.sumblocks, 'w');
		write(1, "\n", 1);
	}
}

void	ft_process_on_way(t_tab *tab, t_info info, int i)
{
	if (ft_strchr_kai(info.flag, 'i'))
	{
		ft_putnbr_write_len(tab[i].node_number, 'w');
		write(1, " ", 1);
	}
	if (ft_strchr_kai(info.flag, 's'))
	{
		ft_put_space(&tab[i]);
		if (ft_strchr_kai(info.flag, 'k'))
			ft_putnbr_write_len(tab[i].blocks / 2, 'w');
		else
			ft_putnbr_write_len(tab[i].blocks, 'w');
		write(1, " ", 1);
	}
	if (ft_strchr_kai(info.flag, 'G'))
		ft_putstr(tab[i].color);
}

void	ft_process_final(t_tab *tab, t_info info, int i)
{
	if (ft_strchr_kai(info.flag, 'F'))
		print_type(tab[i].mode);
	else if (ft_strchr_kai(info.flag, 'p'))
		print_type_dir(tab[i].mode);
	ft_putstr(RESET);
	if (!ft_strchr_kai(info.flag, 'm'))
		write(1, "\n", 1);
	else
		write(1, ", ", 2);
}
