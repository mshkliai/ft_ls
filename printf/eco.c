/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eco.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:34:40 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/10 13:34:34 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	fd(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == '0' || str[i] == '#'
				|| str[i] == '+' || str[i] == '-'))
		i++;
	return (i);
}

void		eco(t_print *st, char *format, char c)
{
	char	str[3][11];

	ft_strclr(str[0]);
	ft_strclr(str[1]);
	st->res = ' ';
	prewidth(format, str[0], str[1]);
	str[0][0] == '0' && ft_strlen(str[0]) && !ft_strchr(str[0], '-') &&
		!ft_strlen(str[1]) ? st->res = '0' : c + 0;
	if (ft_atoi(str[0] + fd(str[0])) < 0 || ft_atoi(str[0] + fd(str[0])) > 0)
		st->i = ft_atoi(str[0] + fd(str[0]));
	if (ft_strchr(format, '-') && st->i > 0)
		st->i *= -1;
	if (ft_atoi(str[1]) >= 0 && ft_isdigit(str[1][0]))
		st->j = ft_atoi(str[1]);
	if (str[1][0] == '.' && ft_strlen(str[1]) == 1)
		st->j = 0;
	if ((st->i == 0 && !ft_isdigit(str[0][0])))
		st->i += 0;
	if (st->j == 0 && !ft_isdigit(str[1][0]))
		st->j = 0;
	if (c == 'd' || c == 'o' || c == 'u')
	{
		str[1][0] == '.' && ft_strlen(str[1]) == 1 ? st->j = 0 : st->j + 0;
		ft_strlen(str[1]) == 0 ? st->j = 1 : st->j + 0;
	}
}
