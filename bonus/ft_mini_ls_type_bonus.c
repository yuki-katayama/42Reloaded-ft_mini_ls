/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_type_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:59:04 by kyuki             #+#    #+#             */
/*   Updated: 2020/12/04 23:52:59 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

static void		print_type_any(mode_t mode)
{
	if (S_ISDIR(mode))
	{
		ft_putstr(RESET);
		write(1, "/", 1);
	}
	else if (S_ISLNK(mode))
	{
		ft_putstr(RESET);
		write(1, "@", 1);
	}
	else if (S_ISFIFO(mode))
	{
		ft_putstr(RESET);
		write(1, "|", 1);
	}
	else if (S_ISSOCK(mode))
	{
		ft_putstr(RESET);
		write(1, "=", 1);
	}
}

void			print_type(mode_t mode)
{
	if (S_ISREG(mode))
	{
		if (mode & (S_IXUSR | S_IXGRP | S_IXOTH))
		{
			ft_putstr(RESET);
			write(1, "*", 1);
		}
	}
	else
		print_type_any(mode);
}

void			print_type_dir(mode_t mode)
{
	if (S_ISDIR(mode))
	{
		ft_putstr(RESET);
		write(1, "/", 1);
	}
}
