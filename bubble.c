/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 13:35:21 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/31 17:36:53 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_ls.h"

static void	by_name(t_file **files)
{
	t_file	*start;
	int		i;
	int		j;
	int		k;

	i = ft_strlen((*files)->name) - len_name((*files)->name) + 1;
	while (1)
	{
		start = *files;
		j = 0;
		while (start)
		{
			k = i;
			if (start->next)
				while (start->name[k] && start->next->name[k]
						&& start->name[k] == start->next->name[k])
					k++;
			start->next && start->name[k] > start->next->name[k]
				? ft_swap(&start, &start->next, &j) : 0;
			start = start->next;
		}
		if (!j)
			break ;
	}
}

static void	check_by_name(t_file **file1, t_file **file2, int i, int *j)
{
	int	k;

	k = i;
	while ((*file1)->name[k] && (*file2)->name[k]
			&& (*file1)->name[k] == (*file2)->name[k])
		k++;
	if ((*file1)->name[k] > (*file2)->name[k])
		ft_swap(file1, file2, j);
}

static void	by_time(t_file **files)
{
	t_file	*start;
	int		j;
	int		i;

	i = ft_strlen((*files)->name) - len_name((*files)->name) + 1;
	while (1)
	{
		start = *files;
		j = 0;
		while (start)
		{
			if (start->next)
			{
				if (start->info.st_mtime < start->next->info.st_mtime)
					ft_swap(&start, &start->next, &j);
				else if (start->info.st_mtime == start->next->info.st_mtime)
					check_by_name(&start, &start->next, i, &j);
			}
			start = start->next;
		}
		if (!j)
			break ;
	}
}

static void	by_size(t_file **files)
{
	t_file	*start;
	int		j;
	int		i;

	i = ft_strlen((*files)->name) - len_name((*files)->name) + 1;
	while (1)
	{
		start = *files;
		j = 0;
		while (start)
		{
			if (start->next)
			{
				if (start->info.st_size < start->next->info.st_size)
					ft_swap(&start, &start->next, &j);
				else if (start->info.st_size == start->next->info.st_size)
					check_by_name(&start, &start->next, i, &j);
			}
			start = start->next;
		}
		if (!j)
			break ;
	}
}

void		bubble(t_file **files)
{
	if (ft_strchr(g_flags, 'S'))
		by_size(files);
	else if (ft_strchr(g_flags, 't'))
		by_time(files);
	else
		by_name(files);
}
