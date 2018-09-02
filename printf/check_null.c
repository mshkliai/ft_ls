/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_null.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:00:20 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/10 17:38:12 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	check_null(char *format)
{
	int	i;

	i = 0;
	while (format[i] && format[i] != '0')
		i++;
	while (i && format[i - 1] != '.' &&
			!ft_isdigit(format[i - 1]))
		i--;
	if (i == 0 && !ft_strchr(format, '-'))
		return ('0');
	return (' ');
}
