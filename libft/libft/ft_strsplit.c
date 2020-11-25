/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:59:27 by jbrisset          #+#    #+#             */
/*   Updated: 2019/06/24 09:53:48 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	size;

	if (!s || !c || !(tab = ft_memalloc(ft_strlen(s) + 1)))
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			size = 0;
			while (s[i + size] && s[i + size] != c)
				size++;
			tab[j++] = ft_strsub(s, i, size);
			i = i + size;
		}
	}
	tab[j] = NULL;
	return (tab);
}
