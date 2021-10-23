/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 13:59:53 by abahmani          #+#    #+#             */
/*   Updated: 2021/04/02 16:14:23 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef unsigned int	t_bool;

# define FALSE 0
# define TRUE 1

# ifndef BUFFSIZE
#  define BUFFSIZE 1048
# endif

typedef	struct			s_arg
{
	t_bool				zero;
	t_bool				minus;
	t_bool				plus;
	t_bool				hashtag;
	t_bool				dot;
	t_bool				sp;
	int					fw;
	int					pre;
	char				conv;
}						t_arg;

typedef	struct			s_pars
{
	char				buf[BUFFSIZE];
	unsigned int		pos_buf;
	unsigned int		pos;
	int					count;
	t_arg				*arg;
}						t_pars;

typedef struct			s_pfct
{
	int					(*f[256])(t_pars *pars, va_list ap);
	t_bool				call;
}						t_pfct;

int						ft_printf(const char *format, ...);
int						ft_isdigit(int c);
int						ft_isprint(int c);
size_t					ft_strlen(const char *s);
int						parse_str(const char *format, t_pars *pars);
int						process_arg(const char *format, t_pars *pars,
						va_list ap, t_pfct *t);
void					check_flags(const char *format, t_pars *pars);
void					init_arg(t_pars *pars);
int						is_conversion(char c);
int						conv_c(t_pars *pars, va_list ap);
void					init_pfct_tab(t_pfct *t);
void					print_buffer(t_pars *pars);
int						parse_desc(const char *format, t_pars *pars,
						va_list ap);
t_bool					isflag(const char *format, int i);
void					take_fw_pre(const char *format, int *num, t_pars *pars,
						va_list ap);
void					add_char(t_pars *pars, char c, int nb);
void					check_fw_pre(const char *format, t_pars *pars,
						va_list ap);
int						conv_s(t_pars *pars, va_list ap);
void					add_str(t_pars *pars, int nb_char, char *str);
int						number_space_s(t_pars *pars, int nb_char);
int						number_char(t_pars *pars, char *str);
int						conv_per(t_pars *pars, va_list ap);
int						conv_id(t_pars *pars, va_list ap);
int						number_space_id(t_pars *pars, int len, int neg);
int						number_zero(t_pars *pars, int len, int neg);
int						digit_count(int nb, int base);
void					add_uint(t_pars *pars, unsigned int nb);
int						conv_u(t_pars *pars, va_list ap);
int						conv_x(t_pars *pars, va_list ap);
void					add_xint(t_pars *pars, unsigned int nb, char *base);
int						conv_p(t_pars *pars, va_list ap);
void					add_p(t_pars *pars, unsigned long nb, char *base);
int						digit_count_p(unsigned long nb);
int						digit_count_u(unsigned int nb, int base);
int						conv_n(t_pars *pars, va_list ap);
int						number_space_u(t_pars *pars, int len, int neg);
int						number_space_p(t_pars *pars, int len);
#endif
