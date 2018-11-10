/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 17:16:52 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/01 11:27:00 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list_ls.h"

void	list_del(t_file *list)
{
	t_file	*start;

	start = list;
	while (start->next)
	{
		ft_strdel(&start->name);
		ft_strdel(&start->pass);
		ft_strdel(&start->group);
		if (start->prev)
			free(start->prev);
		start = start->next;
	}
	free(start->prev);
	ft_strdel(&start->name);
	ft_strdel(&start->pass);
	ft_strdel(&start->group);
	free(start);
}
