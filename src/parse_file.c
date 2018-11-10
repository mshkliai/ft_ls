/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 10:56:39 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/31 13:19:57 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list_ls.h"

void	parse_file(t_stat info, char *name, t_file **files)
{
	mode_t	m;

	m = info.st_mode;
	if (S_ISCHR(m) || S_ISBLK(m) || S_ISREG(m) || S_ISFIFO(m) ||
			S_ISSOCK(m) || S_ISLNK(m))
		add_file(files, name);
	else
		out_error(2, name);
}
