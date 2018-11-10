/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 17:54:40 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/31 19:21:46 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list_ls.h"

int	count_spaces(int num)
{
	int	num2;
	int	space;

	space = 1;
	num2 = num;
	while (num2 /= 10)
		space++;
	return (space);
}
