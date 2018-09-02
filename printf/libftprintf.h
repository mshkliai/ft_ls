/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 19:14:23 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/03 14:16:06 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define BUFF_SIZE 1

# include "./libft/libft.h"
# include <stdarg.h>

typedef	struct				s_print
{
	char					w;
	va_list					ap;
	char					*end;
	char					end2[4096];
	char					buf[4096];
	long long int			i;
	int						j;
	int						j2;
	int						res;
}							t_print;

int							get_next_line(const int fd, char **line);
int							itoa_base(unsigned long long int num, int base,
							char *str, int s);
int							d_strlen(char *str);
int							len_to(char *str, char c);
void						prewidth(char *format, char *str, char *str2);
int							width(int i, int sym);
void						eco(t_print *st, char *format, char c);
int							demo_itoa(long long int n, char *str, char plus);
int							demo_itoa_2(unsigned int n, char *str, char plus);
int							conv_s(char *format, char *str);
int							conv_d(char *form, long long int n);
int							conv_i(char *form, unsigned int n);
char						check_null(char *format);
int							conv_c(char *format, char c);
int							conv_p(char *format, void *point);
int							conv_o_2(char *format, unsigned long long int n);
int							conv_u(char *format, unsigned long long int n);
int							help_d(char *str, t_print num, int s, char w);
int							conv_x_2(char *fo, unsigned long long int n);
int							len_uni(wchar_t s);
int							len_wchr(wchar_t *str, int l);
int							conv_nu_c(char *format, wchar_t s);
int							conv_nu_s(char *format, wchar_t *str);
int							len_c(char *str, char c);
int							unsign(char *fo, unsigned long long int n, char w);
int							integer(char *fo, long long int n, char w);
int							validator(char symb);
void						flag(char *end, int i, t_print *fl);
int							wat_flag(t_print *wat);
int							ft_printf(const char *format, ...);

#endif
