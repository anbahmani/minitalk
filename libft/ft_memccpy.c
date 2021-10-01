/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:57:03 by abahmani          #+#    #+#             */
/*   Updated: 2021/09/26 22:20:33 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;

	i = 0;
	(unsigned char*)src;
	(unsigned char*)dest;
	while (i < n && (unsigned char)*src != (unsigned char)c)
	{
		(unsigned char)*dest = (unsigned char)*src;
		dest++;
		src++;
		i++;
	}
	return (i == n ? NULL : ++dest);
}
