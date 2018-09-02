/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_nu_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:44:33 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/10 14:02:31 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	twobits(unsigned int s)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	oct;
	int				res;
	unsigned int	o3;

	o3 = ((49280 << 12));
	res = 0;
	o2 = (s << 26) >> 26;
	o1 = ((s >> 6) << 27) >> 27;
	oct = (49280 >> 8) | o1;
	res += write(1, &oct, 1);
	oct = ((o3 << 12) >> 24) | o2;
	res += write(1, &oct, 1);
	return (res);
}

static int	threebits(unsigned int s)
{
	unsigned char	o[4];
	unsigned char	oct;
	int				res;
	unsigned int	op[5];

	res = 0;
	o[0] = (s << 26) >> 26;
	o[1] = ((s >> 6) << 26) >> 26;
	o[2] = ((s >> 12) << 28) >> 28;
	o[3] = '\0';
	op[0] = (14712960 << 8);
	op[1] = op[0] << 8;
	op[2] = 14712960 << 8;
	oct = (14712960 >> 16) | o[2];
	res += write(1, &oct, 1);
	oct = ((op[2] << 8) >> 24) | o[1];
	res += write(1, &oct, 1);
	oct = ((op[1] << 8) >> 24) | o[0];
	res += write(1, &oct, 1);
	return (res);
}

static int	fourbits(unsigned int s)
{
	unsigned char	o[5];
	unsigned char	oct;
	int				res;

	res = 0;
	o[0] = (s << 26) >> 26;
	o[1] = ((s >> 6) << 26) >> 26;
	o[2] = ((s >> 12) << 26) >> 26;
	o[3] = ((s >> 18) << 29) >> 29;
	o[4] = '\0';
	oct = (4034953344 >> 24) | o[3];
	res += write(1, &oct, 1);
	oct = ((4034953344 << 8) >> 24) | o[2];
	res += write(1, &oct, 1);
	oct = ((4034953344 << 16) >> 24) | o[1];
	res += write(1, &oct, 1);
	oct = ((4034953344 << 24) >> 24) | o[0];
	res += write(1, &oct, 1);
	return (res);
}

static int	howbit(unsigned int s)
{
	char		buf[33];
	int			i;
	int			res;

	res = 0;
	i = itoa_base(s, 2, buf, 0);
	i <= 7 ? res += write(1, &s, 1) : res + 0;
	i <= 11 && i > 7 ? res += twobits(s) : res + 0;
	i <= 16 && i > 11 ? res += threebits(s) : res + 0;
	i > 16 ? res += fourbits(s) : res + 0;
	return (res);
}

int			conv_nu_c(char *format, wchar_t s)
{
	t_print			un;
	int				size;
	char			buf[33];

	size = itoa_base((unsigned int)s, 2, buf, 0);
	size <= 7 ? size = 1 : size + 0;
	size <= 11 && size > 7 ? size = 2 : size + 0;
	size <= 16 && size > 11 ? size = 3 : size + 0;
	size > 16 ? size = 4 : size + 0;
	ft_strclr(buf);
	un.res = 0;
	un.i = 0;
	eco(&un, format, 'C');
	un.j = check_null(format);
	un.res = 0;
	un.i < 0 ? un.res += howbit((unsigned int)s)
		+ width(-un.i - size, un.j) : s + 0;
	un.i > 0 ? un.res += width(un.i - size, un.j)
		+ howbit((unsigned int)s) : s + 0;
	!un.i ? un.res += howbit((unsigned int)s) : un.res + 0;
	return (un.res);
}
