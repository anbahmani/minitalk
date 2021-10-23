/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_per.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 10:35:41 by abahmani          #+#    #+#             */
/*   Updated: 2021/10/15 16:40:45 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	conv_per(t_pars *pars, va_list ap)
{
	(void)ap;
	if (pars->arg->plus || pars->arg->hashtag)
		return (0);
	if (pars->arg->sp)
		return (0);
	if (pars->arg->zero && !pars->arg->minus)
		add_char(pars, '0', pars->arg->fw - 1);
	else if (!pars->arg->minus)
		add_char(pars, ' ', pars->arg->fw - 1);
	add_char(pars, '%', 1);
	if (pars->arg->minus)
		add_char(pars, ' ', pars->arg->fw - 1);
	return (1);
}
