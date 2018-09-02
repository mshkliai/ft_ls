/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 12:45:10 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/31 17:39:02 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_ls.h"

void	out_error(int num, char *name)
{
	int	i;

	i = ft_strlen(name) - len_name(name) + 1;
	if (num == 1)
	{
		write(2, "ft_ls: ", 7);
		write(2, name + i, ft_strlen(name + i));
		write(2, ": Permission denied\n", 20);
	}
	else if (num == 2)
	{
		write(2, "ft_ls: ", 7);
		write(2, name, ft_strlen(name));
		write(2, ": No such file or directory\n", 28);
	}
}
