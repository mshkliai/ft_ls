/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_mass.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 11:30:44 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/31 16:32:02 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_ls.h"

int	sorting_mass(char **mass)
{
	char	*buff;
	int		i;
	int		j;

	if (!mass)
		return (0);
	while (1)
	{
		i = -1;
		j = 0;
		while (mass[++i])
			if (mass[i + 1] && (mass[i][0] > mass[i + 1][0] || (mass[i][0] ==
				mass[i + 1][0] && ft_strlen(mass[i]) > ft_strlen(mass[i + 1]))))
			{
				buff = mass[i];
				mass[i] = mass[i + 1];
				mass[i + 1] = buff;
				j++;
			}
		if (!j)
			break ;
	}
	return (1);
}
