/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 10:15:10 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/01 09:51:45 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list_ls.h"

static void	print_color(t_file *file, int i)
{
	mode_t	m;

	m = file->info.st_mode;
	if (file->is_dir == 1)
		ft_printf("\e[1;36m%s\e[0m", file->name + i);
	else if (S_ISLNK(file->info.st_mode))
		ft_printf("\e[0;35m%s\e[0m", file->name + i);
	else if (S_ISSOCK(file->info.st_mode))
		ft_printf("\e[1;33m%s\e[0m", file->name + i);
	else if (S_ISBLK(m))
		ft_printf("\e[0;34m%s\e[0m", file->name + i);
	else if (S_ISCHR(m))
		ft_printf("\e[0;32;3m%s\e[0m", file->name + i);
	else if (m & S_IXUSR || m & S_IXGRP || m & S_IXOTH)
		ft_printf("\e[0;31m%s\e[0m", file->name + i);
	else
		ft_putstr(file->name + i);
}

void		print_file(t_file *file, int allow)
{
	int		i;
	char	buff[1025];

	i = 0;
	if (ft_strlen(file->name) > 1)
		i = ft_strlen(file->name) - len_name(file->name) + 1;
	if (ft_strchr(g_flags, 'G'))
		print_color(file, i);
	else
		ft_putstr(file->name + i);
	if (S_ISLNK(file->info.st_mode))
	{
		ft_strchr(g_flags, 'l') ? read_link(file->name, buff) : 0;
		ft_strchr(g_flags, 'l') ? ft_printf(" -> %s", buff) : 0;
	}
	if (allow)
	{
		allow -= ft_strlen(file->name + i);
		width(allow, ' ');
	}
	else if (allow != -1)
		ft_printf("\n");
}
