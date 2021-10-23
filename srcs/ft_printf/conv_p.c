/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:50:38 by abahmani          #+#    #+#             */
/*   Updated: 2021/10/15 16:40:45 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		digit_count_p(unsigned long nb)
{
	int cpt;

	cpt = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 16;
		cpt++;
	}
	return (cpt);
}

void	add_p(t_pars *pars, unsigned long nb, char *base)
{
	if (nb < 16)
		add_char(pars, base[nb], 1);
	else
	{
		add_p(pars, nb / 16, base);
		add_p(pars, nb % 16, base);
	}
}

int		number_space_p(t_pars *pars, int len)
{
	int nb_element;

	nb_element = number_zero(pars, len, 0) + len + 2;
	if (pars->arg->fw - nb_element > 0)
		return (pars->arg->fw - nb_element);
	return (0);
}

int		conv_p(t_pars *pars, va_list ap)
{
	int				nb_space;
	unsigned long	nb;
	int				len;

	nb = (unsigned long)va_arg(ap, void*);
	len = digit_count_p(nb) - (!nb && pars->arg->dot && !pars->arg->pre);
	nb_space = number_space_p(pars, len);
	if (!pars->arg->minus)
		add_char(pars, ' ', nb_space);
	add_str(pars, 2, "0x");
	len -= (!nb && pars->arg->dot && pars->arg->pre);
	add_char(pars, '0', number_zero(pars, len, 0));
	if (!(pars->arg->dot && nb == 0))
		add_p(pars, nb, "0123456789abcdef");
	if (pars->arg->minus)
		add_char(pars, ' ', nb_space);
	return (1);
}
