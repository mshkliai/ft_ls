/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:47:50 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/10 15:07:22 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	percent_nu_c(char *fo, wchar_t c, char i)
{
	if (i == 'C' || (i == 'c' && len_c(fo, 'l') == 1))
		return (conv_nu_c(fo, c));
	return (0);
}

static int	percent_d_i(char *fo, long long int c)
{
	t_print	di;

	di.res = 0;
	if (di.i == 'D')
		return (conv_d(fo, (unsigned char)c));
	if (ft_strchr(fo, 'l'))
	{
		len_c(fo, 'l') == 2 ? di.res +=
			conv_d(fo, (long long)c) : di.res + 0;
		len_c(fo, 'l') == 1 ? di.res += conv_d(fo, (long)c) : di.res + 0;
	}
	else if (ft_strchr(fo, 'h'))
	{
		len_c(fo, 'h') == 1 ? di.res += conv_d(fo, (short)c) : di.res + 0;
		len_c(fo, 'h') == 2 ? di.res += conv_d(fo, (char)c) : di.res + 0;
	}
	else if (len_c(fo, 'j') == 1 || ft_strchr(fo, 'h'))
		return (conv_d(fo, (intmax_t)c));
	else if (len_c(fo, 'z') == 1)
		return (conv_d(fo, (size_t)c));
	else
		return (conv_d(fo, (int)c));
	return (di.res);
}

int			integer(char *fo, long long int n, char w)
{
	if (w == 'D')
		return (percent_d_i(fo, (long)n));
	if (w == 'c' && !ft_strchr(fo, 'l'))
		return (conv_c(fo, (int)n));
	if (w == 'c' || w == 'C')
		return (percent_nu_c(fo, (int)n, w));
	if (w == 'd' || w == 'i')
		return (percent_d_i(fo, n));
	return (0);
}
