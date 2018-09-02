/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:16:22 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/03 14:12:07 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_printf(const char *format, ...)
{
	t_print	pr;
	int		rs;

	ft_strcpy(pr.end2, format);
	va_start(pr.ap, format);
	rs = 0;
	pr.res = 0;
	pr.j = 0;
	while (pr.j != -1)
	{
		pr.i = 0;
		ft_strclr(pr.buf);
		flag(pr.end2, pr.j, &pr);
		pr.j2 = pr.j;
		ft_strclr(pr.buf);
		rs += wat_flag(&pr);
		rs += pr.res;
	}
	va_end(pr.ap);
	return (rs);
}
