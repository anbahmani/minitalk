/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 10:44:44 by abahmani          #+#    #+#             */
/*   Updated: 2021/09/26 22:20:33 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		isinset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	int			count;
	char		*str;

	i = 0;
	j = ft_strlen(s1);
	if (j != 0)
		j--;
	count = 0;
	while (i < j && (isinset(s1[i], set) || isinset(s1[j], set)))
	{
		if (isinset(s1[i], set))
			i++;
		if (isinset(s1[j], set))
			j--;
	}
	str = malloc(sizeof(char) * (j - i + 2));
	if (!str)
		return (NULL);
	return (ft_substr(s1, i, j - i + 1));
}
