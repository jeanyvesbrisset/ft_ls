/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:14:53 by jbrisset          #+#    #+#             */
/*   Updated: 2018/11/17 17:18:38 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (ft_strlen(dst) < size)
		len = ft_strlen(dst);
	else
		len = size;
	len += ft_strlen(src);
	if (size)
	{
		while (*dst)
		{
			dst++;
			i++;
		}
		while (*src && i < size - 1)
		{
			*dst++ = *src++;
			i++;
		}
		*dst = '\0';
	}
	return (len);
}
