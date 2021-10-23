/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:15:19 by abahmani          #+#    #+#             */
/*   Updated: 2021/10/15 16:40:45 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_buffer(t_pars *pars)
{
	unsigned int i;

	i = 0;
	while (i < pars->pos_buf)
		write(1, &pars->buf[i++], 1);
	pars->pos_buf = 0;
}

void	add_char(t_pars *pars, char c, int nb)
{
	while (nb-- > 0)
	{
		pars->buf[pars->pos_buf++] = c;
		pars->count++;
		if (pars->pos_buf >= BUFFSIZE)
			print_buffer(pars);
	}
}

int		parse_str(const char *format, t_pars *pars)
{
	while (format[pars->pos] && format[pars->pos] != '%')
	{
		pars->buf[pars->pos_buf++] = format[pars->pos++];
		pars->count++;
	}
	if (!format[pars->pos])
		return (1);
	pars->pos++;
	return (0);
}
