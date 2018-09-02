/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prewidth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:12:31 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/03 14:23:26 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	cpyto(char *str, char *format, int i)
{
	int	k;

	k = 0;
	while (format[i])
	{
		if (!ft_isdigit(format[i]) && format[i] != '-' && format[i] == '.')
			break ;
		str[k] = format[i];
		k++;
		i++;
	}
	str[k] = '\0';
}

static void	eeee(char *format, char *str2, int i)
{
	if (!ft_isdigit(format[i]))
		ft_strcpy(str2, ".");
	else
		cpyto(str2, format, i);
	str2[ft_strlen(str2)] = '\0';
}

void		prewidth(char *format, char *str, char *str2)
{
	int		i;
	int		n[2];

	i = -1;
	n[0] = 0;
	n[1] = 0;
	while (format[++i] && (!n[0] || !n[1]))
	{
		if (format[i - 1] != '.' && !n[0])
		{
			if (format[i - 1] == '-' && ft_isdigit(format[i]))
				cpyto(str, format, i - 1);
			else if (format[i - 1] != '-' && ft_isdigit(format[i]))
				cpyto(str, format, i);
			ft_strlen(str) > 0 ? n[0] = 1 : n[0] + 0;
		}
		if (format[i - 1] == '.' && !n[1])
		{
			eeee(format, str2, i);
			ft_strlen(str2) > 0 ? n[1] = 1 : n[1] + 0;
		}
		i += d_strlen(format + i);
	}
}
