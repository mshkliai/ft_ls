/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_separate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 18:21:12 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/31 17:31:35 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list_ls.h"

char	*join_separate(char *line, char *line2, char separate)
{
	char	*start;
	char	*end;
	int		i;

	i = -1;
	end = ft_strnew(ft_strlen(line) + ft_strlen(line2) + 1);
	start = line;
	while (*start)
	{
		end[++i] = *start;
		start++;
	}
	if (ft_strcmp(line, "/"))
		end[++i] = separate;
	start = line2;
	while (*start)
	{
		end[++i] = *start;
		start++;
	}
	return (end);
}
