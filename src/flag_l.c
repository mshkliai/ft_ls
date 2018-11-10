/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:15:44 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/01 12:31:15 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list_ls.h"

static void	print_type(mode_t mode)
{
	if (S_ISLNK(mode))
		ft_printf("l");
	else if (S_ISDIR(mode))
		ft_printf("d");
	else if (S_ISCHR(mode))
		ft_printf("c");
	else if (S_ISBLK(mode))
		ft_printf("b");
	else if (S_ISFIFO(mode))
		ft_printf("p");
	else if (S_ISSOCK(mode))
		ft_printf("s");
	else
		ft_printf("-");
}

static void	print_rights(t_file *files, t_file *start)
{
	mode_t	m;

	m = files->info.st_mode;
	print_type(m);
	m & S_IRUSR ? ft_printf("r") : ft_printf("-");
	m & S_IWUSR ? ft_printf("w") : ft_printf("-");
	if (m & S_ISUID || m & S_ISGID)
		m & S_IXUSR ? ft_printf("s") : ft_printf("S");
	else
		m & S_IXUSR ? ft_printf("x") : ft_printf("-");
	m & S_IRGRP ? ft_printf("r") : ft_printf("-");
	m & S_IWGRP ? ft_printf("w") : ft_printf("-");
	if (S_ISUID & m || S_ISGID & m)
		m & S_IXGRP ? ft_printf("s") : ft_printf("S");
	else
		m & S_IXGRP ? ft_printf("x") : ft_printf("-");
	m & S_IROTH ? ft_printf("r") : ft_printf("-");
	m & S_IWOTH ? ft_printf("w") : ft_printf("-");
	if (m & S_ISVTX)
		m & S_IXOTH ? ft_printf("t") : ft_printf("T");
	else
		m & S_IXOTH ? ft_printf("x") : ft_printf("-");
	ft_printf("  ");
	width(max_space(start, 1) - count_spaces(files->info.st_nlink), ' ');
	ft_putnbr(files->info.st_nlink);
}

static void	print_spec_nums(t_file *files, t_file *start)
{
	int		min;
	int		maj;

	min = minor(files->info.st_rdev);
	maj = major(files->info.st_rdev);
	width(max_space(start, 5) - count_spaces(maj), ' ');
	ft_printf("   %d,", maj);
	width(max_space(start, 4) - count_spaces(min) - 1, ' ');
	ft_printf("%d", min);
}

static void	print_all(t_file *files, t_file *start)
{
	char	*time;

	print_rights(files, start);
	ft_printf(" %s", files->pass);
	width(max_space(start, 2) - ft_strlen(files->pass), ' ');
	ft_printf("  %s", files->group);
	width(max_space(start, 3) - ft_strlen(files->group), ' ');
	if (S_ISCHR(files->info.st_mode) || S_ISBLK(files->info.st_mode))
		print_spec_nums(files, start);
	else
	{
		width(max_space_size(start, files), ' ');
		ft_printf("  %d", files->info.st_size);
	}
	time = ctime(&files->info.st_mtime);
	ft_strchr(g_flags, 'T') ? ft_printf(" %.20s ", time + len_to(time, ' '))
		: ft_printf(" %.12s ", time + len_to(time, ' '));
	print_file(files, -1);
}

void		flag_l(t_file *files, int total)
{
	t_file	*start;
	int		size;

	size = 1;
	bubble(&files);
	start = files;
	while (start->next)
	{
		size += start->info.st_blocks;
		start = start->next;
	}
	total ? ft_printf("total ") : 0;
	total ? ft_putnbr(size - 1 + start->info.st_blocks) : 0;
	total ? ft_printf("\n") : 0;
	!ft_strchr(g_flags, 'r') ? start = files : 0;
	while (start)
	{
		print_all(start, files);
		if (size_list(files) > 1 ||
				(size_list(files) == 1 && ft_strchr(g_flags, 'R')))
			ft_printf("\n");
		ft_strchr(g_flags, 'r') ? start = start->prev : 0;
		!ft_strchr(g_flags, 'r') ? start = start->next : 0;
	}
	files ? list_del(files) : 0;
}
