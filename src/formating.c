/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:30:11 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/01 10:02:15 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list_ls.h"

static int	count_files(t_file *files)
{
	t_file	*start;
	int		max;
	int		res;

	max = -1;
	start = files;
	while (start)
	{
		if (len_name(start->name) > max)
			max = len_name(start->name);
		start = start->next;
	}
	res = 100 / max;
	if (!res)
		res = 1;
	return (res);
}

static int	count_columns(t_file *files, int files_in_str)
{
	int		columns;
	int		size;

	size = size_list(files);
	columns = size / files_in_str;
	if (size % files_in_str > 0)
		columns++;
	return (columns);
}

static void	clear_mass_lists(t_file **mass)
{
	int		i;

	i = 0;
	while (mass[i])
	{
		list_del(mass[i]);
		i++;
	}
	free(mass);
}

void		formating(t_file *files)
{
	t_file	*start;
	t_file	**buf;
	int		files_in_str;
	int		j;

	files_in_str = count_files(files);
	if (!files_in_str)
		return ;
	buf = sort_in_columns(&files, count_columns(files, files_in_str));
	j = -1;
	while (buf[++j])
	{
		start = buf[j];
		while (start->next)
		{
			print_file(start, 100 / files_in_str);
			start = start->next;
		}
		!j && !buf[j + 1] && !ft_strchr(g_flags, 'R') ?
			print_file(start, -1) : print_file(start, 0);
	}
	clear_mass_lists(buf);
	list_del(files);
}
