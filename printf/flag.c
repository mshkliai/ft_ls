/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:57:00 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/10 10:26:36 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	comp(char symb)
{
	char	buf[15];
	int		i;

	i = 0;
	ft_strcpy(buf, "sSpdDioOuUxXcC");
	buf[14] = '\0';
	while (buf[i])
	{
		if (buf[i] == symb)
			return (1);
		i++;
	}
	return (0);
}

static int	l(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	return (i);
}

static int	find_flag(char *end, int *i)
{
	int	res;

	res = 0;
	while (end[*i])
	{
		if (end[*i] == '%')
			break ;
		res += write(1, end + *i, l(end + *i));
		*i += l(end + *i) - 1;
		*i += 1;
	}
	return (res);
}

void		flag(char *end, int i, t_print *fl)
{
	int		j;
	int		n;

	j = 0;
	n = 0;
	fl->res = find_flag(end, &i);
	while (end[i + j] && !n)
	{
		if (!validator(end[i + j]))
			n = 2;
		if (comp(end[i + j]) || (end[i + j] == '%' && j > 0))
		{
			fl->i = end[i + j];
			n = 1;
		}
		j++;
	}
	n == 1 ? i += j : i + 0;
	ft_strcpy(fl->buf, end + i);
	if ((!ft_strlen(fl->buf) && !fl->i) || n == 2 ||
			(!n && end[j + i + 1] == '\0'))
		fl->j = -1;
	else
		fl->j = i;
}
