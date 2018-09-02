/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:19:01 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/09 19:16:10 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	hs(char *format, char *str, unsigned long long int n, t_print *oct)
{
	int		size;

	size = 0;
	if (ft_strchr(format, '#'))
	{
		ft_strcpy(str, "0");
		size++;
	}
	oct->res = itoa_base(n, 8, str + size, 0) + size;
	oct->j = oct->res;
	size = oct->res;
	oct->res = 0;
	oct->i = 0;
	eco(oct, format, 'o');
	(oct->j == 0 && n == 0) || (ft_strchr(format, '#') && oct->j && n == 0)
		? size -= 1 : size + 0;
	return (size);
}

int			conv_o_2(char *format, unsigned long long int n)
{
	t_print	oct;
	char	str[4096];
	int		size;
	char	w;

	size = hs(format, str, n, &oct);
	w = oct.res;
	oct.res = 0;
	if (oct.i < 0)
	{
		oct.j > size ? oct.res += width(oct.j - size, '0') +
				write(1, str, size) + width(-oct.i - oct.j, w)
			: oct.res + write(1, str, size) + width(-oct.i - size, w);
		(oct.res == 0) && size >= -oct.i ? oct.res += size : oct.res + 0;
		(oct.res == 0) && size < -oct.i ? oct.res += -oct.i : oct.res + 0;
	}
	else
	{
		oct.j > size ? oct.res += (width(oct.i - oct.j, w)
				+ width(oct.j - size, '0') + write(1, str, size)) :
			oct.res + width(oct.i - size, w) + write(1, str, size);
		oct.res == 0 && size >= oct.i ? oct.res += size : oct.res + 0;
		oct.res == 0 && size < oct.i ? oct.res += oct.i : oct.res + 0;
	}
	return (oct.res);
}
