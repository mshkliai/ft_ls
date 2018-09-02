/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:22:39 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/10 15:05:48 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	negative(long long int *i, int *size, int *b, char plus)
{
	if (*i < 0 || plus == '+')
	{
		*i < 0 ? *i *= -1 : *i + 0;
		*size = 1;
		*b = 1;
	}
}

int				demo_itoa(long long int n, char *str, char plus)
{
	t_print			a;
	int				size2;
	long long int	i;

	a.j = 0;
	a.res = 0;
	i = n;
	if (i == -8223372036854775808 - 1000000000000000000)
	{
		ft_strcpy(str, "-9223372036854775808");
		return (ft_strlen(str));
	}
	negative(&n, &a.res, &a.j, plus);
	while (i /= 10)
		a.res++;
	if (a.j > 0 || plus == '+')
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
