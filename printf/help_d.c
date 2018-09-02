/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 09:31:21 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/09 19:18:22 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	help_d(char *str, t_print num, int s, char w)
{
	int	res;

	res = 0;
	num.i < 0 && w == '0' && ft_strchr(str, '-') ? res += write(1, "-", 1) +
		width(num.i - s, w) + write(1, str + 1, s - 1) : res + 0;
	num.i > 0 && w == '0' && ft_strchr(str, '-') ? res += write(1, "-", 1) +
		width(num.i - s, w) + write(1, str + 1, s - 1) : res + 0;
	return (res);
}
