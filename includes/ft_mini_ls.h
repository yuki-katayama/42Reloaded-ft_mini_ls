/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 22:47:39 by kyuki             #+#    #+#             */
/*   Updated: 2020/12/02 22:47:43 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_MINI_LS_H
# define _FT_MINI_LS_H

# include <stdio.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# define NOT_PATH -1

typedef struct	s_tab
{
	time_t			m_time;
	time_t			n_time;
	char			*s;
}				t_tab;

void			ft_sort_by_sec_nsec_name(t_tab *tab, unsigned long int len);
int				ft_count_path(DIR *dp);
void			ft_set_info(t_tab *tab, DIR *dp);
int				ft_mini_ls(void);

#endif
