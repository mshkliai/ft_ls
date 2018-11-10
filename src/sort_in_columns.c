/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_columns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 12:14:23 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/31 17:52:34 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list_ls.h"

static t_file	**reading_list(t_file **files, int *i, int columns)
{
	t_file	**end;

	bubble(files);
	*i = -1;
	end = (t_file**)malloc(sizeof(t_file) * columns);
	return (end);
}

t_file			**sort_in_columns(t_file **files, int columns)
{
	t_file	*start;
	t_file	**end;
	int		i;

	end = reading_list(files, &i, columns + 1);
	start = *files;
	while (++i < columns)
		end[i] = 0;
	if (ft_strchr(g_flags, 'r'))
		get_end(&start);
	while (start)
	{
		i = -1;
		while (start && ++i < columns)
		{
			add_file(&end[i], start->name);
			ft_strchr(g_flags, 'r') ? start = start->prev : 0;
			!ft_strchr(g_flags, 'r') ? start = start->next : 0;
		}
		if (!start)
			break ;
	}
	end[columns] = 0;
	return (end);
}
