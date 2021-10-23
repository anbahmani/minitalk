/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:12:19 by abahmani          #+#    #+#             */
/*   Updated: 2021/10/15 16:40:45 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X' || c == '%' || c == 'n')
		return (1);
	return (0);
}

t_bool	isflag(const char *format, int i)
{
	if (format[i] == '0' && format[i - 1] != '.')
		return (TRUE);
	else if (format[i] == '-')
		return (TRUE);
	else if (format[i] == '+')
		return (TRUE);
	else if (format[i] == '#')
		return (TRUE);
	else if (format[i] == ' ')
		return (TRUE);
	return (FALSE);
}

void	check_flags(const char *format, t_pars *pars)
{
	while (isflag(format, pars->pos))
	{
		if (format[pars->pos] == '0')
			pars->arg->zero = TRUE;
		else if (format[pars->pos] == '-')
			pars->arg->minus = TRUE;
		else if (format[pars->pos] == '+')
			pars->arg->plus = TRUE;
		else if (format[pars->pos] == '#')
			pars->arg->hashtag = TRUE;
		else if (format[pars->pos] == ' ')
			pars->arg->sp = TRUE;
		pars->pos++;
	}
}

void	take_fw_pre(const char *format, int *num, t_pars *pars,
					va_list ap)
{
	if (ft_isdigit(format[pars->pos]))
	{
		while (ft_isdigit(format[pars->pos]))
		{
			*num += format[pars->pos] - '0';
			if (ft_isdigit(format[pars->pos + 1]))
				*num *= 10;
			pars->pos++;
		}
	}
	else if (format[pars->pos] == '*')
	{
		*num = va_arg(ap, int);
		pars->pos++;
	}
}

void	check_fw_pre(const char *format, t_pars *pars, va_list ap)
{
	take_fw_pre(format, &pars->arg->fw, pars, ap);
	if (format[pars->pos - 1] == '*' && pars->arg->fw < 0)
	{
		pars->arg->fw *= -1;
		pars->arg->minus = TRUE;
	}
	if (format[pars->pos] == '.')
	{
		pars->arg->dot = TRUE;
		pars->pos++;
		take_fw_pre(format, &pars->arg->pre, pars, ap);
		if (pars->arg->pre < 0)
			pars->arg->dot = FALSE;
	}
}
