/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <jbrisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:42:53 by jbrisset          #+#    #+#             */
/*   Updated: 2018/11/09 18:36:30 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;
	int length;

	i = 0;
	length = (int)len;
	while ((src[i] != '\0') && (i < length))
	{
		dst[i] = src[i];
		i++;
	}
	while (i < length)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
