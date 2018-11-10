/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:37:27 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/28 12:26:43 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list_ls.h"

int	len_name(char *name)
{
	char	*start;

	start = name + ft_strlen(name) - 1;
	while (*start && *start != '/')
		start--;
	if (!ft_strlen(start))
		return (ft_strlen(name) + 1);
	return (ft_strlen(start));
}
