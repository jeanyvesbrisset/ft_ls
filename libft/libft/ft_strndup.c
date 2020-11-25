/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 23:56:15 by jbrisset          #+#    #+#             */
/*   Updated: 2018/11/17 00:25:12 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (dup)
	{
		while (str[i] && i < n)
		{
			dup[i] = str[i];
			i++;
		}
		dup[i] = '\0';
	}
	return (dup);
}
