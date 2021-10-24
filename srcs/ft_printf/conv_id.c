/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:01:41 by abahmani          #+#    #+#             */
/*   Updated: 2021/10/24 12:51:06 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	digit_count(int nb, int base)
{
	int	cpt;

	cpt = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= base;
		cpt++;
	}
	return (cpt);
}

int	number_zero(t_pars *pars, int len, int neg)
{
	if (pars->arg->dot && pars->arg->pre > len)
		return (pars->arg->pre - len);
	else if (!pars->arg->dot && pars->arg->zero && pars->arg->fw - neg > len)
		return (pars->arg->fw - neg - len - (2 * pars->arg->conv == 'p'));
	return (0);
}

int	number_space_id(t_pars *pars, int len, int neg)
{
	int	nb_element;

	nb_element = number_zero(pars, len, neg) + len + neg;
	nb_element += !neg && !pars->arg->plus && pars->arg->sp;
	if (pars->arg->fw - nb_element > 0)
		return (pars->arg->fw - nb_element);
	return (0);
}

void	add_int(t_pars *pars, int nb)
{
	if (nb == -2147483648)
		add_str(pars, 10, "2147483648");
	else
	{
		if (nb < 0)
			nb = -nb;
		if (nb < 10)
			add_char(pars, nb + 48, 1);
		else
		{
			add_int(pars, nb / 10);
			add_int(pars, nb % 10);
		}
	}
}

int	conv_id(t_pars *pars, va_list ap)
{
	int	nb_space;
	int	nb;
	int	len;

	if (pars->arg->minus && pars->arg->zero)
		pars->arg->zero = FALSE;
	nb = va_arg(ap, int);
	len = digit_count(nb, 10) - (!nb && pars->arg->dot && !pars->arg->pre);
	add_char(pars, ' ', nb >= 0 && !pars->arg->plus && pars->arg->sp);
	nb_space = number_space_id(pars, len, nb < 0);
	add_char(pars, ' ', nb_space * (!pars->arg->minus));
	add_char(pars, '-', nb < 0);
	add_char(pars, '+', nb >= 0 && pars->arg->plus);
	add_char(pars, '0', number_zero(pars, len, nb < 0));
	if (!(nb == 0 && pars->arg->dot == TRUE && pars->arg->pre == 0))
		add_int(pars, nb);
	add_char(pars, ' ', nb_space * pars->arg->minus);
	return (1);
}
