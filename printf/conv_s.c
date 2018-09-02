/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 10:08:06 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/10 17:08:54 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	output(t_print a, int fl, char *str)
{
	int	res;

	res = 0;
	fl == 1 ? res += (write(1, str, a.j2) + width(-a.i - a.j2, a.w))
		: res + write(1, str, a.j) + width(-a.i - a.j, a.w);
	return (res);
}

int			conv_s(char *format, char *str)
{
	t_print	a;

	if (!str)
		str = "(null)";
	a.j = (int)ft_strlen(str);
	a.j2 = a.j;
	a.i = 0;
	eco(&a, format, 's');
	if (!ft_strlen(str) && !a.i)
		return (0);
	a.w = check_null(format);
	a.res = 0;
	if (a.i < 0)
	{
		a.j > a.j2 ? a.res += output(a, 1, str) : a.res + output(a, 2, str);
		a.res == 0 ? a.res += -a.i : a.w + 0;
	}
	else
	{
		a.j > a.j2 ? a.res += width(a.i - a.j2, a.w) + write(1, str, a.j2) :
			a.res + (width(a.i - a.j, a.w) + write(1, str, a.j));
		a.res == 0 && a.j >= a.i ? a.res += a.j : a.res + 0;
		a.res == 0 && a.j < a.i ? a.res += a.i : a.res + 0;
	}
	return (a.res);
}
