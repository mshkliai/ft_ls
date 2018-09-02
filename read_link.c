/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 18:02:35 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/31 18:03:35 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_ls.h"

void	read_link(char *name, char *buff)
{
	int		i;

	buff[0] = 0;
	readlink(name, buff, 1024);
	i = 0;
	while (buff[i] && (ft_isdigit(buff[i]) || ft_isalpha(buff[i])
				|| buff[i] == '/' || buff[i] == '.'))
		i++;
	buff[i] = 0;
}
