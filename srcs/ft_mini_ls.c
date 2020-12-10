/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 22:47:32 by kyuki             #+#    #+#             */
/*   Updated: 2020/12/02 22:47:34 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

static void		ft_put_result(t_tab *tab)
{
	unsigned long int i;

	i = 0;
	while (tab[i].s)
	{
		ft_putstr(tab[i].s);
		write(1, "\n", 1);
		i++;
	}
}

static void		all_free(t_tab *tab)
{
	unsigned long int	i;

	i = 0;
	while (tab[i].s)
	{
		free(tab[i].s);
		i++;
	}
	free(tab);
}

int				ft_mini_ls(void)
{
	DIR						*dp;
	t_tab					*tab;
	unsigned long int		sumpath;

	if ((dp = opendir("./")) == NULL)
	{
		perror(NULL);
		return (NOT_PATH);
	}
	sumpath = ft_count_path(dp);
	closedir(dp);
	if ((tab = malloc((sizeof(t_tab)) * (sumpath + 1))) == NULL)
		return (NOT_PATH);
	if ((dp = opendir("./")) == NULL)
	{
		perror(NULL);
		return (NOT_PATH);
	}
	ft_set_info(tab, dp);
	ft_sort_by_sec_nsec_name(tab, sumpath);
	ft_put_result(tab);
	all_free(tab);
	closedir(dp);
	return (0);
}
