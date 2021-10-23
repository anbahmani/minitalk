/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:58:44 by abahmani          #+#    #+#             */
/*   Updated: 2021/10/15 16:40:45 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	conv_n(t_pars *pars, va_list ap)
{
	int	*nb;

	nb = va_arg(ap, int*);
	*nb = pars->count;
	return (1);
}
