/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:31:17 by abahmani          #+#    #+#             */
/*   Updated: 2021/09/26 22:20:33 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*tmp_s1;
	char	*tmp_s2;

	i = 0;
	tmp_s1 = (char*)s1;
	tmp_s2 = (char*)s2;
	while (*tmp_s1 && *tmp_s2 && *tmp_s1 == *tmp_s2 && i < n)
	{
		tmp_s1++;
		tmp_s2++;
		i++;
	}
	return (*tmp_s1 - *tmp_s2);
}
