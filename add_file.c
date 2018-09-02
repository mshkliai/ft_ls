/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 11:09:10 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/01 11:26:02 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_ls.h"

static t_file	*fulling_values(char *name)
{
	t_file	*new_file;
	t_pass	*pass;
	t_group	*group;

	new_file = (t_file*)malloc(sizeof(t_file));
	new_file->name = ft_strdup(name);
	lstat(name, &new_file->info);
	pass = getpwuid(new_file->info.st_uid);
	group = getgrgid(new_file->info.st_gid);
	new_file->pass = ft_strdup(pass->pw_name);
	new_file->group = ft_strdup(group->gr_name);
	new_file->is_dir = S_ISDIR(new_file->info.st_mode);
	return (new_file);
}

void			add_file(t_file **files, char *name)
{
	t_file	*new_file;
	t_file	*start;

	new_file = fulling_values(name);
	if (!*files || !ft_strcmp(name, ".") || !ft_strcmp(name, ".."))
	{
		new_file->next = *files;
		*files = new_file;
		(*files)->prev = 0;
		if ((*files)->next)
			(*files)->next->prev = (*files);
	}
	else
	{
		start = *files;
		get_end(&start);
		new_file->prev = start;
		start->next = new_file;
		new_file->next = 0;
	}
}
