/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:43:28 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/10 15:05:20 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	output(t_print num, char w, int wat, t_print a)
{
	wat == 0 ? a.res += (write(1, "+", 1) + width(num.j - a.j + 1, '0') +
		write(1, a.end2 + 1, a.j - 1) + width(-num.i - num.j - 1, w)) : wat + 0;
	wat == 1 ? a.res += width(num.i - num.j - 1, w) + write(1, "+", 1) +
				width(num.j - a.j + 1, '0')
				+ write(1, a.end2 + 1, a.j - 1) : wat + 0;
	wat == 2 ? a.res += write(1, a.end2, a.j) +
		width(-num.i - a.j, w) : wat + 0;
	wat == 3 ? a.res += width(num.i - a.j, w) + write(1, a.end2, a.j) : wat + 0;
	wat == 4 ? a.res += write(1, "+", 1) + width(num.i - a.j, w)
		+ write(1, a.end2 + 1, a.j - 1) : wat + 0;
	return (a.res);
}

static int	plus(char *format, t_print num, unsigned int n, char w)
{
	t_print	a;

	a.res = 0;
	if (ft_strchr(format, '+'))
	{
		a.j = demo_itoa_2(n, a.end2, '+');
		ft_atoi(a.end2) == 0 && num.j == 0 ? a.j -= 1 : a.j + 0;
		if (w == '0')
			return (output(num, w, 4, a));
		if (num.j >= (a.j - 1))
		{
			num.i < 0 ? a.res += output(num, w, 0, a) :
				a.res + output(num, w, 1, a);
			a.res == 0 && num.j >= num.i ? a.res += num.j + 1 : a.res + 0;
			a.res == 0 && num.j < num.i ? a.res += num.i : a.res + 0;
		}
		else
		{
			num.i < 0 ? a.res += output(num, w, 2, a) :
				a.res + output(num, w, 3, a);
			a.res == 0 && a.j >= num.i ? a.res += a.j : a.res + 0;
			a.res == 0 && a.j < num.i ? a.res += num.i : a.res + 0;
		}
	}
	return (a.res);
}

static	int	minus(char *str, t_print num, unsigned int *s, char w)
{
	int	res;

	res = 0;
	*s = demo_itoa_2(*s, str, '-');
	if ((res = help_d(str, num, *s, w)) > 0)
		return (res);
	if ((unsigned int)num.j > (*s - 1) && ft_strchr(str, '-'))
	{
		num.i < 0 ? res += (write(1, "-", 1) + width(num.j - *s + 1, '0') +
		write(1, str + 1, *s - 1) + width(-num.i - num.j - 1, w)) :
		width(num.i - num.j - 1, w) + write(1, "-", 1) +
		width(num.j - *s + 1, '0') + write(1, str + 1, *s - 1);
		res == 0 && num.j >= num.i ? res += num.j + 1 : res + 0;
		res == 0 && num.j < num.i ? res += num.i : res + 0;
	}
	else if ((unsigned int)num.j <= (*s - 1) && ft_strchr(str, '-'))
	{
		num.i < 0 ? res += write(1, str, *s) + width(-num.i - *s, w) :
		res + width(num.i - *s, w) + write(1, str, *s);
		res == 0 && *s >= num.i ? res += *s : res + 0;
		res == 0 && *s < num.i ? res += num.i : res + 0;
	}
	return (res);
}

static int	simple(t_print num, int s, char *str, char w)
{
	if (num.i < 0)
	{
		ft_strchr(num.end, ' ') ? num.res += (width(1, ' ')) : num.res + 0;
		num.res > 0 ? num.i += 1 : num.i + 0;
		num.j > s ? num.res += (width(num.j - s, '0') +
				write(1, str, s) + width(-num.i - num.j, w))
			: num.res + (write(1, str, s) + width(-num.i - s, w));
		(num.res == 0 || (num.res == 1 && ft_strchr(num.end, ' ')))
			&& s >= -num.i ? num.res += s : num.res + 0;
		(num.res == 0 || (num.res == 1 && ft_strchr(num.end, ' ')))
			&& s < -num.i ? num.res += -num.i : num.res + 0;
	}
	else
	{
		ft_strchr(num.end, ' ') ? num.res += (width(1, ' ')) : num.res + 0;
		num.res > 0 ? num.i -= 1 : num.i + 0;
		num.j > s ? num.res += (width(num.i - num.j, w)
				+ width(num.j - s, '0') + write(1, str, s)) :
			num.res + (width(num.i - s, w) + write(1, str, s));
		(num.res == 0 || (num.res == 1 && ft_strchr(num.end, ' ')))
			&& s >= num.i ? num.res += s : num.res + 0;
		(num.res == 0 || (num.res == 1 && ft_strchr(num.end, ' ')))
			&& s < num.i ? num.res += num.i : num.res + 0;
	}
	return (num.res);
}

int			conv_i(char *form, unsigned int n)
{
	t_print	num;
	char	str[4096];

	num.end = form;
	num.j = n;
	num.i = 0;
	eco(&num, form, 'd');
	num.w = num.res;
	num.res = 0;
	if ((num.res = plus(form, num, n, num.w)
				+ minus(str, num, &n, num.w)) > 0)
		return (num.res);
	else
	{
		ft_atoi(str) == 0 && num.j == 0 ? n -= 1 : n + 0;
		num.res += simple(num, n, str, num.w);
	}
	return (num.res);
}
