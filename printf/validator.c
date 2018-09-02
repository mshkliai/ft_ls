/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 10:24:01 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/09 19:19:44 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	validator(char symb)
{
	char	buf[35];
	int		i;

	i = 0;
	ft_strcpy(buf, "0123456789.%-+lhjz# sSpdDioOuUxXcC");
	while (buf[i])
	{
		if (buf[i] == symb)
			return (1);
		i++;
	}
	return (0);
}
