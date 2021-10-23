/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:10:50 by abahmani          #+#    #+#             */
/*   Updated: 2021/10/15 16:40:45 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				init_pfct_tab(t_pfct *t)
{
	t->call = TRUE;
	t->f[(unsigned int)'c'] = &conv_c;
	t->f[(unsigned int)'s'] = &conv_s;
	t->f[(unsigned int)'%'] = &conv_per;
	t->f[(unsigned int)'i'] = &conv_id;
	t->f[(unsigned int)'d'] = &conv_id;
	t->f[(unsigned int)'u'] = &conv_u;
	t->f[(unsigned int)'x'] = &conv_x;
	t->f[(unsigned int)'X'] = &conv_x;
	t->f[(unsigned int)'p'] = &conv_p;
	t->f[(unsigned int)'n'] = &conv_n;
}

void				init_arg(t_pars *pars)
{
	pars->arg->zero = FALSE;
	pars->arg->minus = FALSE;
	pars->arg->plus = FALSE;
	pars->arg->hashtag = FALSE;
	pars->arg->dot = FALSE;
	pars->arg->sp = FALSE;
	pars->arg->fw = 0;
	pars->arg->pre = 0;
}
