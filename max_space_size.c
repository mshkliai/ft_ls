/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_space_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 12:15:47 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/01 13:20:16 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_ls.h"

static		int	check_majmin(t_file *file)
{
	while (file)
	{
		if (S_ISCHR(file->info.st_mode) || S_ISBLK(file->info.st_mode))
			return (1);
		file = file->next;
	}
	return (0);
}

int				max_space_size(t_file *file, t_file *files)
{
	t_file	*start;
	int		max;

	start = file;
	max = -1;
	if (check_majmin(start))
		return (max_space(start, 4) + max_space(start, 5));
	else
	{
		while (start)
		{
			if (count_spaces(start->info.st_size) > max)
				max = count_spaces(start->info.st_size);
			start = start->next;
		}
	}
	return (max - count_spaces(files->info.st_size));
}
