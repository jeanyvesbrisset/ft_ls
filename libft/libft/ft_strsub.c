/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:48:39 by jbrisset          #+#    #+#             */
/*   Updated: 2018/11/17 16:14:00 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char	*s;
	int		i;
	int		j;
	char	*result;

	if (!str)
		return (NULL);
	s = (char *)str;
	i = 0;
	j = (int)start;
	result = ft_strnew(len);
	if (result)
	{
		while (s[j] != '\0' && i < (int)len)
		{
			result[i] = s[j];
			i++;
			j++;
		}
		result[i] = '\0';
	}
	return (result);
}
