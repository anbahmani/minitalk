/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:50:55 by abahmani          #+#    #+#             */
/*   Updated: 2021/10/15 16:40:45 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	parse_desc(const char *format, t_pars *pars, va_list ap)
{
	check_flags(format, pars);
	check_fw_pre(format, pars, ap);
	if (!is_conversion(format[pars->pos]))
		return (0);
	pars->arg->conv = format[pars->pos];
	pars->pos++;
	return (1);
}

int	process_arg(const char *format, t_pars *pars, va_list ap,
					t_pfct *t)
{
	init_arg(pars);
	if (!t->call)
		init_pfct_tab(t);
	if (!parse_desc(format, pars, ap))
		return (0);
	if (!t->f[(unsigned int)pars->arg->conv](pars, ap))
		return (0);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	t_pars	pars;
	t_pfct	t;
	va_list	ap;
	t_arg	ar;

	pars.pos = 0;
	pars.count = 0;
	t.call = FALSE;
	pars.buf[BUFFSIZE - 1] = '\0';
	pars.pos_buf = 0;
	pars.arg = &ar;
	va_start(ap, format);
	while (1)
	{
		if (parse_str(format, &pars))
			break ;
		if (!process_arg(format, &pars, ap, &t))
			return (0);
	}
	print_buffer(&pars);
	va_end(ap);
	return (pars.count);
}
