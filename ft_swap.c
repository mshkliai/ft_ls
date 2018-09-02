/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 14:45:43 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/01 12:32:24 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_ls.h"

void	ft_swap(t_file **file1, t_file **file2, int *j)
{
	char	*buf;
	char	*pass;
	char	*group;
	int		is_dir;
	t_stat	info;

	j ? *j = 1 : 0;
	pass = (*file1)->pass;
	(*file1)->pass = (*file2)->pass;
	(*file2)->pass = pass;
	group = (*file1)->group;
	(*file1)->group = (*file2)->group;
	(*file2)->group = group;
	buf = (*file1)->name;
	(*file1)->name = (*file2)->name;
	(*file2)->name = buf;
	is_dir = (*file1)->is_dir;
	(*file1)->is_dir = (*file2)->is_dir;
	(*file2)->is_dir = is_dir;
	info = (*file1)->info;
	(*file1)->info = (*file2)->info;
	(*file2)->info = info;
	buf = 0;
	pass = 0;
	group = 0;
}
