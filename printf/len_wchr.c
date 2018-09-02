/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_wchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 10:45:45 by mshkliai          #+#    #+#             */
/*   Updated: 2018/05/09 19:19:14 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	len_wchr(wchar_t *str, int l)
{
	int	i;
	int	res;
	int	iterator;

	i = -1;
	res = 0;
	if (!l)
	{
		while (str[++i])
		{
			iterator = len_uni(str[i]);
			res += iterator;
		}
		return (res);
	}
	else
		while (res < l && str[++i])
		{
			iterator = len_uni(str[i]);
			res += iterator;
		}
	return (res - len_uni(str[i]));
}
