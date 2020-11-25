/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:59:04 by jbrisset          #+#    #+#             */
/*   Updated: 2018/11/17 14:30:35 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	int				i;
	char			c;
	char			*newstr;
	unsigned int	index;

	if (!(str || f))
		return (NULL);
	if (!(newstr = ft_strnew(ft_strlen(str))))
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		index = (unsigned int)i;
		c = f(index, str[i]);
		newstr[i] = c;
		i++;
	}
	return (newstr);
}
