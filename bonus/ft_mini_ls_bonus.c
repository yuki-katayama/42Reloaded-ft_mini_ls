/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 22:45:35 by kyuki             #+#    #+#             */
/*   Updated: 2020/12/04 23:48:14 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

static void			ft_path_filter(t_info *info)
{
	info->base_len = ft_strlen(info->base_path);
	if (info->base_len > PATH_MAX)
	{
		ft_putstr(strerror(ARG_TOO_LONG));
		return ;
	}
	ft_strncpy(info->full_path, info->base_path, PATH_MAX);
	if (info->full_path[info->base_len - 1] != '/')
	{
		info->full_path[info->base_len] = '/';
		info->base_len++;
		info->full_path[info->base_len] = '\0';
	}
}

static void			set_info(t_tab *tab, t_info *info,
							struct dirent *dent, int *i)
{
	struct stat	dent_stat;

	ft_strncpy(&info->full_path[info->base_len], dent->d_name,
			PATH_MAX - (unsigned int)info->base_len);
	if (lstat(info->full_path, &dent_stat) != 0)
	{
		perror(info->full_path);
		return ;
	}
	tab[*i].s = ft_strdup(dent->d_name);
	tab[*i].mode = dent_stat.st_mode;
	choice_color(tab[*i].mode, &tab[*i]);
	tab[*i].m_time = dent_stat.st_mtimespec.tv_sec;
	tab[*i].n_time = dent_stat.st_mtimespec.tv_nsec;
	tab[*i].blocks = dent_stat.st_blocks;
	tab[*i].node_number = dent->d_ino;
	tab[*i].blocks_keta = 3 - ft_putnbr_write_len(tab[*i].blocks, 'l');
	tab[*i].file_size = dent_stat.st_size;
	info->sumblocks += tab[*i].blocks;
	*i += 1;
}

static void			ft_put_path(t_tab *tab, t_info info, DIR *dir)
{
	int				i;
	struct dirent	*dent;

	i = 0;
	while ((dent = readdir(dir)) != NULL)
		if (dent->d_name[0] != '.' &&
			!ft_strchr_kai(info.flag, 'a') && !ft_strchr_kai(info.flag, 'A'))
			set_info(tab, &info, dent, &i);
		else if (ft_strchr_kai(info.flag, 'a') || ft_strchr_kai(info.flag, 'A'))
			set_info(tab, &info, dent, &i);
	i = 0;
	ft_process_start(tab, info);
	while (tab[i].s)
	{
		ft_process_on_way(tab, info, i);
		ft_putstr(tab[i].s);
		ft_process_final(tab, info, i);
		i++;
	}
}

static void			ft_mini_ls_bonus_initial(t_info info)
{
	DIR		*dir;
	t_tab	*tab;

	if ((dir = opendir(info.base_path)) == NULL)
	{
		perror(NULL);
		return ;
	}
	info.sumpath = count_path(dir, info);
	closedir(dir);
	if ((tab = malloc((sizeof(t_tab)) * (info.sumpath + 1))) == NULL)
		return ;
	tab[info.sumpath].s = NULL;
	if ((dir = opendir(info.base_path)) == NULL)
	{
		perror(info.base_path);
		return ;
	}
	ft_path_filter(&info);
	ft_put_path(tab, info, dir);
	all_free(tab, info);
	closedir(dir);
}

int					ft_mini_ls_bonus(int argc, char **argv)
{
	t_info	info;
	int		i;

	i = 1;
	info.sumblocks = 0;
	info.base_path = ft_strdup("./");
	if (argc > 1)
	{
		while (argv[i] && i < 3)
		{
			if (argv[i][0] == '-')
				info.flag = argv[i];
			else
				info.base_path = ft_strdup(argv[i]);
			i++;
		}
		if (info.base_path == NULL)
			return (NOT_PATH);
	}
	ft_mini_ls_bonus_initial(info);
	return (1);
}
