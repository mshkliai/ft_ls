/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 11:27:08 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/01 12:35:59 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list_ls.h"

static int	max_nlink(t_file *file)
{
	int	max;

	max = -1;
	while (file)
	{
		if (count_spaces(file->info.st_nlink) > max)
			max = count_spaces(file->info.st_nlink);
		file = file->next;
	}
	return (max);
}

static int	max_group_pass(t_file *file, int flag)
{
	int	max;

	max = -1;
	if (flag == 2)
	{
		while (file)
		{
			if ((int)ft_strlen(file->pass) > max)
				max = (int)ft_strlen(file->pass);
			file = file->next;
		}
	}
	else
	{
		while (file)
		{
			if ((int)ft_strlen(file->group) > max)
				max = (int)ft_strlen(file->group);
			file = file->next;
		}
	}
	return (max);
}

static int	max_minor(t_file *file)
{
	int	max;

	max = -1;
	while (file)
	{
		if (count_spaces(minor(file->info.st_rdev)) > max)
			max = count_spaces(minor(file->info.st_rdev));
		file = file->next;
	}
	return (max);
}

static int	max_major(t_file *file)
{
	int	max;

	max = -1;
	while (file)
	{
		if (count_spaces(major(file->info.st_rdev)) > max)
			max = count_spaces(major(file->info.st_rdev));
		file = file->next;
	}
	return (max);
}

int			max_space(t_file *file, int flag)
{
	t_file	*start;

	start = file;
	if (flag == 1)
		return (max_nlink(start));
	else if (flag == 2 || flag == 3)
		return (max_group_pass(start, flag));
	else if (flag == 4)
		return (max_minor(start));
	else if (flag == 5)
		return (max_major(start));
	return (0);
}
