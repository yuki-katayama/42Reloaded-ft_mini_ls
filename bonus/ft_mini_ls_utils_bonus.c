/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 22:45:45 by kyuki             #+#    #+#             */
/*   Updated: 2020/12/04 23:08:58 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

int			count_path(DIR *dir, t_info info)
{
	struct dirent	*dent;
	int				i;

	i = 0;
	while ((dent = readdir(dir)) != NULL)
	{
		if (dent->d_name[0] == '.'
		&& (!ft_strchr_kai(info.flag, 'a') && !ft_strchr_kai(info.flag, 'A')))
			i -= 1;
		i++;
	}
	return (i);
}

char		*ft_strchr_kai(const char *s, int c)
{
	size_t	length;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	length = ft_strlen(s) + 1;
	while (i < length)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			return (&((char *)s)[i]);
		}
		i++;
	}
	return (NULL);
}

void		ft_put_space(t_tab *tab)
{
	size_t i;

	i = 0;
	while (i < tab->blocks_keta)
	{
		write(1, " ", 1);
		i++;
	}
}

int			ft_putnbr_write_len(long long nb, char mode)
{
	int	len;

	len = 0;
	if (nb > 9)
		len = ft_putnbr_write_len(nb / 10, mode);
	if (mode == 'w')
		write(1, &"0123456789"[nb % 10], 1);
	return (len + 1);
}

void		all_free(t_tab *tab, t_info info)
{
	unsigned long int	i;

	i = 0;
	while (tab[i].s)
	{
		free(tab[i].s);
		free(tab[i].color);
		i++;
	}
	free(info.base_path);
	free(tab);
}
