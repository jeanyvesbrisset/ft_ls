/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <jbrisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 06:37:57 by jbrisset          #+#    #+#             */
/*   Updated: 2018/11/14 19:37:45 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char		*dup;
	size_t		len;

	len = ft_strlen(src);
	dup = ft_strnew(len);
	if (dup)
	{
		ft_strcpy(dup, src);
		return (dup);
	}
	return (dup);
}
