/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 09:28:35 by abahmani          #+#    #+#             */
/*   Updated: 2021/09/26 22:20:33 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	count_str(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i + 1] && s[i] == c && s[i + 1] != c)
			count++;
		if (i == 0 && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

char	*split_str(char const *s, char c, size_t begin)
{
	size_t	i;
	size_t	j;
	size_t	count;
	char	*str;

	i = begin;
	j = 0;
	count = 0;
	while (s[begin] && s[begin++] != c)
	{
		count++;
	}
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	while (i < begin - 1)
	{
		str[j++] = s[i++];
	}
	str[j] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	nb_str;
	char	**tab_str;

	i = 0;
	j = 0;
	nb_str = count_str(s, c);
	tab_str = malloc(sizeof(char*) * (nb_str + 1));
	if (!tab_str)
		return (NULL);
	tab_str[nb_str] = NULL;
	while (j < nb_str)
	{
		if (s[i] != c)
		{
			tab_str[j] = split_str(s, c, i);
			i += ft_strlen(tab_str[j]);
			j++;
		}
		else
			i++;
	}
	return (tab_str);
}
