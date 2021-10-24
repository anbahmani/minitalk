/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:20:13 by abahmani          #+#    #+#             */
/*   Updated: 2021/10/24 12:32:23 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	add_xint(t_pars *pars, unsigned int nb, char *base)
{
	if (nb < 16)
		add_char(pars, base[nb], 1);
	else
	{
		add_xint(pars, nb / 16, base);
		add_xint(pars, nb % 16, base);
	}
}

int	conv_x(t_pars *pars, va_list ap)
{
	int				nb_space;
	unsigned int	nb;
	int				len;

	if (pars->arg->minus && pars->arg->zero)
		pars->arg->zero = FALSE;
	nb = va_arg(ap, unsigned int);
	len = digit_count_p(nb) - (pars->arg->dot && !pars->arg->pre && !nb);
	nb_space = number_space_id(pars, len, 0);
	if (!pars->arg->minus)
		add_char(pars, ' ', nb_space);
	add_char(pars, '0', number_zero(pars, len, 0));
	if (pars->arg->hashtag && nb)
	{
		add_char(pars, '0', 1);
		add_char(pars, pars->arg->conv, 1);
	}
	if (pars->arg->conv == 'x' && !(pars->arg->dot && !pars->arg->pre && !nb))
		add_xint(pars, nb, "0123456789abcdef");
	if (pars->arg->conv == 'X' && !(pars->arg->dot && !pars->arg->pre && !nb))
		add_xint(pars, nb, "0123456789ABCDEF");
	if (pars->arg->minus)
		add_char(pars, ' ', nb_space);
	return (1);
}
