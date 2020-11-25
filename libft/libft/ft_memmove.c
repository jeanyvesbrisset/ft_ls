/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 22:50:19 by jbrisset          #+#    #+#             */
/*   Updated: 2018/11/16 23:47:40 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	d = dst;
	s = (char *)src;
	i = 0;
	if (d < s)
	{
		while (i < len)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			*(d + (len - 1)) = *(s + (len - 1));
			len--;
		}
	}
	return (dst);
}
