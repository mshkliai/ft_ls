/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:39:15 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/10 14:02:18 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			conv_c(char *format, char c)
{
	t_print	ch;
	int		i;

	ch.i = 0;
	i = 0;
	eco(&ch, format, 'c');
	ch.w = check_null(format);
	ch.res = 0;
	ch.i > 0 ? ch.res += width(ch.i - 1, ch.w) + write(1, &c, 1) : ch.res + 0;
	ch.i <= 0 ? ch.res += write(1, &c, 1) + width(-ch.i - 1, ch.w) : ch.res + 0;
	return (ch.res);
}
