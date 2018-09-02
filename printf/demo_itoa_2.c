/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo_itoa_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:07:40 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/10 15:05:26 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	pluss(int *size, int *b, char plus)
{
	if (plus == '+')
	{
		*size = 1;
		*b = 1;
	}
}

int				demo_itoa_2(unsigned int n, char *str, char plus)
{
	t_print				a;
	int					size2;
	unsigned int		i;

	a.j = 0;
	a.res = 0;
	i = n;
	pluss(&a.res, &a.j, plus);
	while (i /= 10)
		a.res++;
	if (plus == '+')
		str[0] = plus;
	size2 = a.res + 1;
	while (a.res + 1 - a.j)
	{
		str[a.res--] = n % 10 + '0';
		n /= 10;
	}
	str[size2] = '\0';
	return (ft_strlen(str));
}
