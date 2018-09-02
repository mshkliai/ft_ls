/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_nu_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 10:11:54 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/11 08:53:32 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	putstr_wchr(wchar_t *str, int l)
{
	int	i;
	int	res;
	int	len;

	i = -1;
	res = 0;
	len = len_wchr(str, l);
	if (l == len)
		while (str[++i])
			res += conv_nu_c("%C", str[i]);
	else
	{
		while (str[++i])
		{
			if (res + len_uni(str[i]) > l)
				break ;
			res += conv_nu_c("%C", str[i]);
		}
	}
	return (res);
}

static void	economy(t_print *uns, char *format, int *l, wchar_t *str)
{
	*l = len_wchr(str, 0);
	uns->i = 0;
	eco(uns, format, 'S');
	uns->j && uns->j < *l ? *l = uns->j : *l + 0;
	ft_strchr(format, ' ') && !ft_strchr(format, '-') &&
		!ft_strchr(format, '.') && !ft_strchr(format, '+')
		? uns->i += 1 : *l + 0;
}

int			conv_nu_s(char *format, wchar_t *str)
{
	t_print	uns;
	int		l;

	economy(&uns, format, &l, str);
	if (!l)
		return (conv_s(format, (char*)str));
	l != len_wchr(str, 0) && uns.i < 0 ? uns.i +=
		len_wchr(str, l) - l + 1 : l + 0;
	l != len_wchr(str, 0) && uns.i > 0 ? uns.i -= len_wchr(str, l) - l : l + 0;
	if (ft_strchr(format, '.') && !uns.j)
	{
		uns.i < 0 ? uns.i *= -1 : uns.i + 0;
		return (width(uns.i, check_null(format)));
	}
	uns.j = check_null(format);
	uns.res = 0;
	uns.i < 0 ? uns.res += putstr_wchr(str, l) +
		width(-uns.i - l, uns.j) : uns.res + 0;
	uns.i > 0 ? uns.res += width(uns.i - l, uns.j) +
		putstr_wchr(str, l) : uns.res + 0;
	!uns.i ? uns.res += putstr_wchr(str, l) : uns.res + 0;
	return (uns.res);
}
