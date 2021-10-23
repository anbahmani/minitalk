/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 08:51:08 by abahmani          #+#    #+#             */
/*   Updated: 2021/10/15 16:40:45 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	conv_c(t_pars *pars, va_list ap)
{
	unsigned char c;

	if (pars->arg->zero || pars->arg->plus || pars->arg->hashtag)
		return (0);
	if (pars->arg->dot || pars->arg->sp)
		return (0);
	c = va_arg(ap, int);
	if (!pars->arg->minus)
		add_char(pars, ' ', pars->arg->fw - 1);
	add_char(pars, c, 1);
	if (pars->arg->minus)
		add_char(pars, ' ', pars->arg->fw - 1);
	return (1);
}
