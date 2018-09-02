/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 13:34:56 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/31 13:35:43 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_ls.h"

int	size_list(t_file *files)
{
	t_file	*start;
	int		size;

	size = 0;
	start = files;
	while (start)
	{
		size++;
		start = start->next;
	}
	return (size);
}
