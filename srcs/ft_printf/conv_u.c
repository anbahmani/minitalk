/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:07:21 by abahmani          #+#    #+#             */
/*   Updated: 2021/10/24 12:53:49 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	digit_count_u(unsigned int nb, int base)
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

void	add_uint(t_pars *pars, unsigned int nb)
{
	if (nb < 10)
		add_char(pars, nb + 48, 1);
	else
	{
		add_uint(pars, nb / 10);
		add_uint(pars, nb % 10);
	}
}

int	number_space_u(t_pars *pars, int len, int neg)
{
	int	nb_element;

	nb_element = number_zero(pars, len, neg) + len + neg;
	if (pars->arg->fw - nb_element > 0)
		return (pars->arg->fw - nb_element);
	return (0);
}

int	conv_u(t_pars *pars, va_list ap)
{
	int				nb_space;
	unsigned int	nb;
	int				len;

	if (pars->arg->minus && pars->arg->zero)
		pars->arg->zero = FALSE;
	nb = va_arg(ap, unsigned int);
	len = digit_count_u(nb, 10) - (!nb && pars->arg->dot && !pars->arg->pre);
	nb_space = number_space_u(pars, len, 0);
	if (!pars->arg->minus)
		add_char(pars, ' ', nb_space);
	add_char(pars, '0', number_zero(pars, len, 0));
	if (!(!nb && pars->arg->dot && !pars->arg->pre))
		add_uint(pars, nb);
	if (pars->arg->minus)
		add_char(pars, ' ', nb_space);
	return (1);
}
