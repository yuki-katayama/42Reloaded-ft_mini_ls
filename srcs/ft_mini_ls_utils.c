/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 22:47:17 by kyuki             #+#    #+#             */
/*   Updated: 2020/12/02 22:47:24 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

int				ft_count_path(DIR *dp)
{
	struct dirent		*dir;
	unsigned long		i;

	i = 0;
	while ((dir = readdir(dp)) != NULL)
	{
		if (dir->d_name[0] != '.')
			i++;
	}
	return (i);
}

void			ft_set_info(t_tab *tab, DIR *dp)
{
	struct stat			st;
	struct dirent		*dir;
	unsigned long int	i;

	i = 0;
	while ((dir = readdir(dp)) != NULL)
	{
		if (dir->d_name[0] != '.')
		{
			lstat(dir->d_name, &st);
			tab[i].s = ft_strdup(dir->d_name);
			tab[i].m_time = st.st_mtimespec.tv_sec;
			tab[i++].n_time = st.st_mtimespec.tv_nsec;
		}
	}
	tab[i].s = NULL;
}

static void		ft_swap(t_tab *tab, unsigned long int i, unsigned long int j)
{
	t_tab tmp;

	tmp = tab[j];
	tab[j] = tab[i];
	tab[i] = tmp;
}

static void		ft_sort_nsec_name(t_tab *tab, unsigned long int len,
								unsigned long int i, unsigned long int j)
{
	time_t min;

	min = tab[i].n_time;
	while (j < len && (tab[i].m_time == tab[j].m_time))
	{
		if (min > tab[j].n_time)
		{
			min = tab[j].n_time;
			ft_swap(tab, i, j);
		}
		else if (ft_strcmp(tab[i].s, tab[j].s) < 0 &&
				(tab[i].n_time == tab[j].n_time))
			ft_swap(tab, i, j);
		j++;
	}
}

void			ft_sort_by_sec_nsec_name(t_tab *tab, unsigned long int len)
{
	unsigned long int		i;
	unsigned long int		j;
	time_t					min;

	j = 0;
	i = 0;
	while (i < len - 1)
	{
		min = tab[i].m_time;
		j = i + 1;
		while (j < len)
		{
			if (min > tab[j].m_time)
			{
				min = tab[j].m_time;
				ft_swap(tab, i, j);
			}
			else if (tab[j].m_time == tab[i].m_time)
				ft_sort_nsec_name(tab, len, i, j);
			j++;
		}
		i++;
	}
}
