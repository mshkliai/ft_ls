/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:08:24 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/01 12:45:21 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list_ls.h"

static void	print_usage(char c)
{
	write(2, "ft_ls: illegal option -- ", 25);
	write(2, &c, 1);
	write(2, "\n", 1);
	write(2, "usage: ls [-GaTltrRs] [file ...]\n", 33);
	exit(0);
}

static void	what_flag(char *line, char *flags, int *index)
{
	char	*start;

	start = line + 1;
	while (*start)
	{
		if (*start != 'l' && *start != 'R' && *start != 'r'
				&& *start != 't' && *start != 'a' && *start != 'G'
				&& *start != 'T' && *start != 'S')
			print_usage(*start);
		if (ft_strchr(flags, *start) == 0)
		{
			flags[*index] = *start;
			*index += 1;
			flags[*index] = 0;
		}
		start++;
	}
}

void		parse_flags(char **av, int *i, char *flags)
{
	int		index;

	*i = 1;
	index = 0;
	flags[0] = 0;
	while (av[*i])
	{
		if (av[*i][0] != '-')
			return ;
		what_flag(av[*i], flags, &index);
		if (!ft_strcmp(av[*i], "-"))
			return ;
		*i += 1;
	}
}
