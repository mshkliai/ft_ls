/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 13:10:06 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/03 14:16:21 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_ls.h"

static void	print_info(t_file *all_files, t_file **new_dir, t_file *directory)
{
	t_stat	info;
	t_file	*start;
	int		i;

	*new_dir = 0;
	i = 0;
	start = all_files;
	if (g_deep && ft_strchr(g_flags, 'R') && ft_strlen(directory->name))
	{
		ft_printf("\n");
		ft_putstr(directory->name);
		ft_printf(":\n");
	}
	while (start)
	{
		lstat(start->name, &info);
		if (S_ISDIR(info.st_mode))
		{
			add_file(new_dir, start->name);
			start->is_dir = 1;
		}
		start = start->next;
	}
	if (all_files)
		!ft_strchr(g_flags, 'l') ? formating(all_files) : flag_l(all_files, 1);
}

static void	list_to_print(char *dir_name, t_file **all_files, DIR *fd)
{
	char	*name;
	t_dir	*file;

	while ((file = readdir(fd)) > 0)
	{
		if (!ft_strchr(g_flags, 'a') && file->d_name[0] != '.')
			name = join_separate(dir_name, file->d_name, '/');
		else if (ft_strchr(g_flags, 'a'))
			name = join_separate(dir_name, file->d_name, '/');
		else
			continue ;
		add_file(all_files, name);
		ft_strdel(&name);
	}
}

static void	check_flags(t_file *directory)
{
	t_file	*new_dir;
	t_file	*all_files;
	t_file	*buf;
	DIR		*fd;

	g_deep++;
	all_files = 0;
	fd = opendir(directory->name);
	!fd ? out_error(1, directory->name) : 0;
	if (!fd)
		return ;
	list_to_print(directory->name, &all_files, fd);
	print_info(all_files, &new_dir, directory);
	new_dir ? bubble(&new_dir) : 0;
	buf = new_dir;
	ft_strchr(g_flags, 'r') && buf ? get_end(&buf) : 0;
	while (ft_strchr(g_flags, 'R') && buf)
	{
		if (buf->name[ft_strlen(buf->name) - 1] != '.')
			check_flags(buf);
		!ft_strchr(g_flags, 'r') ? buf = buf->next : 0;
		ft_strchr(g_flags, 'r') ? buf = buf->prev : 0;
	}
	new_dir ? list_del(new_dir) : 0;
	closedir(fd);
}

static void	first_files(char **path, t_file **dirs, t_file **files)
{
	char	buff[1025];
	t_stat	info;
	int		i;

	*dirs = 0;
	*files = 0;
	i = -1;
	!sorting_mass(path) ? add_file(dirs, ".") : 0;
	while (path && path[++i])
	{
		lstat(path[i], &info);
		if (S_ISDIR(info.st_mode))
			add_file(dirs, path[i]);
		else if (S_ISLNK(info.st_mode) &&
				!ft_strchr(g_flags, 'l') && !ft_strchr(path[i], '/'))
		{
			read_link(path[i], buff);
			add_file(dirs, buff);
		}
		else
			parse_file(info, path[i], files);
		info.st_mode = 0;
	}
	if (*dirs && ft_strchr(g_flags, 'S'))
		bubble(dirs);
}

void		ls_end(char **path)
{
	t_file	*directories;
	t_file	*files;
	t_file	*start;

	first_files(path, &directories, &files);
	if (files)
		!ft_strchr(g_flags, 'l') ? formating(files) : flag_l(files, 0);
	files ? ft_printf("\n") : 0;
	directories ? bubble(&directories) : 0;
	start = directories;
	while (start)
	{
		size_list(directories) > 1 && !ft_strchr(g_flags, 'R')
			? ft_printf("%s:\n", start->name) : 0;
		check_flags(start);
		start->next ? ft_printf("\n") : 0;
		start = start->next;
	}
	directories ? list_del(directories) : 0;
}
