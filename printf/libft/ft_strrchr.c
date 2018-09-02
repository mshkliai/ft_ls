/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 19:58:48 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/22 20:53:20 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	while (i >= 0)
	{
		if (*(str + i) == c)
			return ((char*)(str + i));
		i--;
	}
	return (0);
}
