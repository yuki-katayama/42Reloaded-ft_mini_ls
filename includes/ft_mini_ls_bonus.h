/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 22:45:41 by kyuki             #+#    #+#             */
/*   Updated: 2020/12/04 23:48:02 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_MINI_LS_BONUS_H
# define _FT_MINI_LS_BONUS_H
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../libft/libft.h"
# define NOT_PATH -1
# define RED "\033[31m"
# define MAGENTA "\033[35m"
# define RESET   "\033[0m"
# define CYAN    "\033[36m"
# define BLUE    "\033[34m"
# define YELLOW  "\033[33m"
# define ARG_TOO_LONG 7

typedef struct		s_tab
{
	time_t			m_time;
	time_t			n_time;
	mode_t			mode;
	off_t			file_size;
	long long int	node_number;
	char			*s;
	char			*color;
	long long		blocks;
	size_t			blocks_keta;
}					t_tab;

typedef struct		s_info
{
	char			*base_path;
	char			full_path[PATH_MAX + 1];
	char			*flag;
	long int		sumpath;
	unsigned long	sumblocks;
	size_t			base_len;
}					t_info;

void				ft_put_space(t_tab *tab);
int					ft_putnbr_write_len(long long nb, char mode);
char				*ft_strchr_kai(const char *s, int c);
void				ft_swap(t_tab *tab, long int i, long int j);
void				ft_sort_rev(t_tab *tab, long int len);
void				ft_sort_by_flag_t(t_tab *tab, unsigned long int len);
void				ft_sort_by_flag_upper_s(t_tab *tab, unsigned long int len);
void				print_type(mode_t mode);
void				choice_color(mode_t mode, t_tab *tab);
void				ft_process_start(t_tab *tab, t_info info);
void				ft_process_on_way(t_tab *tab, t_info info, int i);
int					ft_mini_ls_bonus(int argc, char **argv);
int					count_path(DIR *dir, t_info info);
void				all_free(t_tab *tab, t_info info);
void				print_type_dir(mode_t mode);
void				ft_process_final(t_tab *tab, t_info info, int i);
#endif
