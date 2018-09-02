/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:43:52 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/09 19:17:01 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	help_x(t_print num, char *str, char *w, int s)
{
	num.res = 0;
	num.j > s ? num.res += (width(num.i - num.j, w[0])
		+ width(num.j - s, '0') + write(1, str, s)) :
	num.res + (width(num.i - s, w[0]) + write(1, str, s));
	(num.res == 0 || (num.res == 2 && ft_strchr(num.end, '#')))
		&& s >= num.i ? num.res += s : num.res + 0;
	(num.res == 0 || (num.res == 2 && ft_strchr(num.end, '#')))
		&& s < num.i ? num.res += num.i : num.res + 0;
	return (num.res);
}

static int	super_economy(t_print num, char *str, char *w, int s)
{
	if (ft_strchr(num.end, '#') && str[0] != '0')
	{
		if (ft_strchr(num.end, '.') && num.i == 0 && str[0] == '0')
			return (width(num.i, w[0]));
		w[0] == '0' ? num.res += write(1, w + 1, 2) +
			width(num.i - 2 - s, w[0]) + write(1, str, s) : s + 0;
		if (num.res > 0)
			return (num.res);
		num.j > s ? num.res += write(1, w + 1, 2) +
			width(num.j - s, '0') + write(1, str, s)
			: num.res + width(num.i - 2 - s, w[0])
			+ write(1, w + 1, 2) + write(1, str, s);
		num.res == 0 && num.i >= s + 2 ? num.res += num.i : num.res + 0;
		num.res == 0 && num.i < s + 2 ? num.res += s + 2 : num.res + 0;
	}
	else
		num.res += help_x(num, str, w, s);
	return (num.res);
}

static int	simple(t_print num, char *str, char *w, int s)
{
	if (num.i < 0)
	{
		ft_strchr(num.end, '#') && (str[0] != '0')
		? num.res += (write(1, w + 1, 2)) : num.res + 0;
		num.res > 0 ? num.i += 2 : num.i + 0;
		num.j > s ? num.res += (width(num.j - s, '0') +
				write(1, str, s) + width(-num.i - num.j, w[0]))
			: num.res + (write(1, str, s) + width(-num.i - s, w[0]));
		(num.res == 0 || (num.res == 2 && ft_strchr(num.end, '#')))
			&& s >= -num.i ? num.res += s : num.res + 0;
		(num.res == 0 || (num.res == 2 && ft_strchr(num.end, '#')))
			&& s < -num.i ? num.res += -num.i : num.res + 0;
	}
	else if (ft_strchr(num.end, '#') && w[0] == '0' && str[0] == '0' &&
			ft_strlen(str) == 1 && !ft_strchr(num.end, '.') && num.i > 0)
		return (width(num.i, w[0]));
	else
		num.res += super_economy(num, str, w, s);
	return (num.res);
}

static int	hsh(char *fo, char *w)
{
	if (ft_strchr(fo, 'x'))
		ft_strcpy(w + 1, "0x");
	else
		ft_strcpy(w + 1, "0X");
	return (0);
}

int			conv_x_2(char *fo, unsigned long long int n)
{
	t_print				num;
	char				str[4096];
	char				w[4];
	int					size;

	size = 0;
	ft_strchr(fo, 'x') ? size += itoa_base(n, 16, str, 0) + hsh(fo, w) : n + 0;
	ft_strchr(fo, 'X') ? size += itoa_base(n, 16, str, 1) + hsh(fo, w) : n + 0;
	num.end = fo;
	num.j = size;
	num.i = 0;
	eco(&num, fo, 'd');
	w[0] = num.res;
	num.res = 0;
	n == 0 && num.j == 0 ? size -= 1 : size + 0;
	num.res += simple(num, str, w, size);
	return (num.res);
}
