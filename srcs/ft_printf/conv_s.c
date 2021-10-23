/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 09:12:06 by abahmani          #+#    #+#             */
/*   Updated: 2021/10/15 16:40:45 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				number_char(t_pars *pars, char *str)
{
	int len;

	len = ft_strlen(str);
	if (pars->arg->dot == TRUE && pars->arg->pre < len)
		return (pars->arg->pre);
	return (len);
}

int				number_space_s(t_pars *pars, int nb_char)
{
	if (pars->arg->fw > nb_char)
		return (pars->arg->fw - nb_char);
	return (0);
}

void			add_str(t_pars *pars, int nb_char, char *str)
{
	if (pars->pos_buf >= BUFFSIZE)
		print_buffer(pars);
	while (nb_char > 0)
	{
		add_char(pars, *str, 1);
		nb_char--;
		str++;
	}
}

int				conv_s(t_pars *pars, va_list ap)
{
	int		nb_space;
	int		nb_char;
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	nb_char = number_char(pars, str);
	nb_space = number_space_s(pars, nb_char);
	if (!pars->arg->minus)
		add_char(pars, ' ', nb_space);
	add_str(pars, nb_char, str);
	if (pars->arg->minus)
		add_char(pars, ' ', nb_space);
	return (1);
}
