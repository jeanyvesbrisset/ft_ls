/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <jbrisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:54:54 by jbrisset          #+#    #+#             */
/*   Updated: 2018/11/17 14:42:51 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	int		k;
	char	length;
	char	*hstack;

	i = 0;
	hstack = (char *)haystack;
	length = (int)len;
	if (needle[i] == '\0')
		return (hstack);
	while (hstack[i] != '\0')
	{
		k = i;
		j = 0;
		while (hstack[k] == needle[j] && needle[j] != '\0' && k < length)
		{
			j++;
			k++;
		}
		if (needle[j] == '\0')
			return (hstack + i);
		i++;
	}
	return (0);
}
