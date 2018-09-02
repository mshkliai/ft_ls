/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_uni.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 10:48:05 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/09 19:19:05 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	len_uni(wchar_t s)
{
	char	buf[33];
	int		size;

	size = itoa_base(s, 2, buf, 0);
	size <= 7 ? size = 1 : size + 0;
	size <= 11 && size > 7 ? size = 2 : size + 0;
	size <= 16 && size > 11 ? size = 3 : size + 0;
	size > 16 ? size = 4 : size + 0;
	ft_strclr(buf);
	return (size);
}
