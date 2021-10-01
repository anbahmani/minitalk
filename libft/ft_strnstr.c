/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:33:05 by abahmani          #+#    #+#             */
/*   Updated: 2021/09/26 22:20:33 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	k = 0;
	if (!*needle)
		return (haystack);
	while (haystack[i] && i < len)
	{
		j = i;
		while (haystack[j] && haystack[j++] == needle[k])
			k++;
		if (!needle[k])
			return (haystack + i);
		else
		{
			k = 0;
			i++;
		}
	}
	return (NULL);
}
