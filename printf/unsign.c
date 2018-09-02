/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:21:06 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/10 15:50:10 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	per_o(char *fo, unsigned long long int n, char w)
{
	if (w == 'O' || (w == 'o' && len_c(fo, 'l') == 1))
		return (conv_o_2(fo, (unsigned long)n));
	if (w == 'o' && len_c(fo, 'h') == 2)
		return (conv_o_2(fo, (unsigned char)n));
	if (w == 'o' && len_c(fo, 'h') == 1)
		return (conv_o_2(fo, (unsigned short)n));
	if ((w == 'o') && len_c(fo, 'l') == 2)
		return (conv_o_2(fo, n));
	if (w == 'o' && len_c(fo, 'j') == 1)
		return (conv_o_2(fo, (uintmax_t)n));
	if (w == 'o' && len_c(fo, 'z') == 1)
		return (conv_o_2(fo, (size_t)n));
	return (conv_o_2(fo, (unsigned int)n));
}

static int	percent_x(char *fo, unsigned long long int n)
{
	t_print	xx;

	xx.res = 0;
	if (len_c(fo, 'l') == 1)
		return (conv_x_2(fo, (unsigned long)n));
	if (len_c(fo, 'h') == 2)
		return (conv_x_2(fo, (unsigned char)n));
	if (len_c(fo, 'h') == 1)
		return (conv_x_2(fo, (unsigned short)n));
	if (len_c(fo, 'l') == 2)
		return (conv_x_2(fo, n));
	if (len_c(fo, 'j') == 1)
		return (conv_x_2(fo, (uintmax_t)n));
	if (len_c(fo, 'z') == 1)
		return (conv_x_2(fo, (size_t)n));
	return (conv_x_2(fo, (unsigned int)n));
}

static int	per_u(char *fo, unsigned long long int n, char w)
{
	if (w == 'U' || (w == 'u' && len_c(fo, 'l') == 1))
		return (conv_u(fo, (unsigned long)n));
	if (w == 'u' && len_c(fo, 'h') == 2)
		return (conv_u(fo, (unsigned char)n));
	if ((w == 'u') && len_c(fo, 'h') == 1)
		return (conv_u(fo, (unsigned short)n));
	if ((w == 'u') && len_c(fo, 'l') == 2)
		return (conv_u(fo, n));
	if ((w == 'u') && len_c(fo, 'j') == 1)
		return (conv_u(fo, (uintmax_t)n));
	if ((w == 'u') && ft_strchr(fo, 'z'))
		return (conv_u(fo, (size_t)n));
	if (len_c(fo, 'h') == 1)
		return (conv_u(fo, (unsigned int)n));
	return (conv_u(fo, (unsigned int)n));
}

int			unsign(char *fo, unsigned long long int n, char w)
{
	if (w == 'D')
		return (conv_d(fo, (long)n));
	if (w == 'o' || w == 'O')
		return (per_o(fo, n, w));
	if (w == 'x' || w == 'X')
		return (percent_x(fo, n));
	if (w == 'u' || w == 'U')
		return (per_u(fo, n, w));
	return (0);
}
