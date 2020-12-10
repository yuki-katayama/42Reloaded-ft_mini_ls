/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_colors_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:58:44 by kyuki             #+#    #+#             */
/*   Updated: 2020/12/04 19:43:38 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

void	choice_color(mode_t mode, t_tab *tab)
{
	if (S_ISREG(mode))
	{
		if (mode & (S_IXUSR | S_IXGRP | S_IXOTH))
			tab->color = ft_strdup(RED);
		else
			tab->color = ft_strdup(RESET);
	}
	else
	{
		if (S_ISDIR(mode))
			tab->color = ft_strdup(BLUE);
		else if (S_ISLNK(mode))
			tab->color = ft_strdup(MAGENTA);
		else if (S_ISFIFO(mode))
			tab->color = ft_strdup(YELLOW);
		else if (S_ISSOCK(mode))
			tab->color = ft_strdup(CYAN);
		else
			tab->color = ft_strdup(RESET);
	}
}
