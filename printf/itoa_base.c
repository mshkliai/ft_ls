/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 09:06:07 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/09 19:18:43 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	itoa_base(unsigned long long int num, int base, char *str, int s)
{
	unsigned long long int	num2;
	int						size;
	int						size2;
	char					buf[16 + 1];

	size = 0;
	num2 = num;
	if (s == 1)
		ft_strcpy(buf, "0123456789ABCDEF");
	else
		ft_strcpy(buf, "0123456789abcdef");
	if (base > 16 || base < 2)
		return (0);
	while (num2 /= base)
		size++;
	size2 = size + 1;
	while (size + 1)
	{
		str[size--] = buf[num % base];
		num /= base;
	}
	str[size2] = '\0';
	return (ft_strlen(str));
}
