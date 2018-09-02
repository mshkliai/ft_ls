/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:21:21 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/10 15:05:09 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	int	nul(char *format, unsigned long long int n, t_print *us)
{
	int		size;

	us->w = ' ';
	size = itoa_base(n, 10, us->end2, 0);
	us->j = size;
	us->i = 0;
	eco(us, format, 'u');
	us->res = 0;
	((format[2] == '0' && ft_strchr(format, ' ')) || (format[1] == '0')) &&
		!ft_strchr(format, '.') &&
		!ft_strchr(format, '-') ? us->w = '0' : us->w + 0;
	ft_strchr(format, '.') && !ft_atoi(us->end2) ? size -= 1 : size + 0;
	return (size);
}

int			conv_u(char *format, unsigned long long int n)
{
	t_print	us;
	int		size;

	size = nul(format, n, &us);
	if (us.i < 0)
	{
		us.j > size ? us.res += width(us.j - size, '0') +
				write(1, us.end2, size) + width(-us.i - us.j, us.w)
			: us.res + write(1, us.end2, size) + width(-us.i - size, us.w);
		(us.res == 0) && size >= -us.i ? us.res += size : us.res + 0;
		(us.res == 0) && size < -us.i ? us.res += -us.i : us.res + 0;
	}
	else
	{
		us.j > size ? us.res += (width(us.i - us.j, us.w)
				+ width(us.j - size, '0') + write(1, us.end2, size)) :
			us.res + width(us.i - size, us.w) + write(1, us.end2, size);
		us.res == 0 && size >= us.i ? us.res += size : us.res + 0;
		us.res == 0 && size < us.i ? us.res += us.i : us.res + 0;
	}
	return (us.res);
}
