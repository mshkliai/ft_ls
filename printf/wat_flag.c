/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wat_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:00:53 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/10 18:15:56 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	percent_nu_s(char *fo, wchar_t *str, char i)
{
	char	r;

	r = 0;
	while (str[(int)r])
		r++;
	if (r < 0)
		return (-1);
	if (i == 'S' || (i == 's' && len_c(fo, 'l') == 1))
		return (conv_nu_s(fo, str));
	return (0);
}

static void	check_pos(t_print *wat)
{
	if (wat->j2 == -1)
		return ;
	wat->j2 > 0 ? wat->j2 -= 1 : wat->j2 + 0;
	wat->i == '%' ? wat->j2 -= 1 : wat->j2 + 0;
	while (wat->end2[wat->j2] != '%')
		wat->j2--;
}

int			wat_flag(t_print *wat)
{
	int		res;
	wchar_t	*buf;

	res = 0;
	check_pos(wat);
	ft_strncpy(wat->buf, wat->end2 + wat->j2,
			len_to(wat->end2 + wat->j2, wat->i));
	if (wat->i == '%')
		res += conv_c(wat->buf, '%');
	if (wat->i == 'i' || wat->i == 'd' || wat->i == 'c' || wat->i == 'C')
		res += integer(wat->buf, va_arg(wat->ap, long long int), wat->i);
	if (((wat->i == 's' && len_c(wat->buf, 'l') == 1) || wat->i == 'S')
			&& (buf = va_arg(wat->ap, wchar_t*)) != NULL)
		res += ((percent_nu_s(wat->buf, buf, wat->i)));
	if (wat->i == 'p')
		res += (conv_p(wat->buf, va_arg(wat->ap, void*)));
	if (wat->i == 'u' || wat->i == 'U' || wat->i == 'x' || wat->i == 'D' ||
			wat->i == 'X' || wat->i == 'o' || wat->i == 'O')
		res += unsign(wat->buf,
				va_arg(wat->ap, unsigned long long int), wat->i);
	if (wat->i == 's' && !res)
		res += conv_s(wat->buf, va_arg(wat->ap, char*));
	ft_strclr(wat->buf);
	ft_strcpy(wat->buf, wat->end2 + len_to(wat->end2, wat->i) + 1);
	return (res);
}
