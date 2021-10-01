/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:58:36 by abahmani          #+#    #+#             */
/*   Updated: 2021/09/26 22:20:33 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t				i;
	const unsigned char	*tsrc;
	unsigned char		*tdest;

	i = 0;
	tsrc = src;
	tdest = dest;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (len > 0)
		{
			tdest[len - 1] = tsrc[len - 1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			tdest[i] = tsrc[i];
			i++;
		}
	}
	return (dest);
}
