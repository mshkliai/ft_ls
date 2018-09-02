/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:20:39 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/10 13:20:09 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	conv_p(char *format, void *point)
{
	char				str[4096];
	char				str2[4096];
	t_print				pt;
	unsigned long int	n;

	n = (unsigned long int)point;
	pt.res = 0;
	pt.i = 0;
	eco(&pt, format, 'p');
	pt.w = pt.res;
	pt.res = 0;
	pt.j = itoa_base(n, 16, str2, 0) + 2;
	ft_strcpy(str, "0x");
	ft_strcat(str, str2);
	pt.i > 0 && pt.w == '0' ? pt.res += write(1, "0x", 2) +
		width(pt.i - pt.j, pt.w) + write(1, str + 2, pt.j - 2) : pt.res + 0;
	pt.i > 0 && pt.w == ' ' ? pt.res += width(pt.i - pt.j, pt.w) +
		write(1, str, pt.j) : pt.res + 0;
	pt.i <= 0 ? pt.res += write(1, str, pt.j) +
		width(-pt.i - pt.j, pt.w) : pt.res + 0;
	return (pt.res);
}
