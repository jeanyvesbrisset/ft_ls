/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:42:08 by jbrisset          #+#    #+#             */
/*   Updated: 2018/11/17 14:50:22 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
{
	int		i;
	char	*newstr;

	if (!(str || f))
		return (NULL);
	if (!(newstr = ft_strnew(ft_strlen(str))))
		return (0);
	i = 0;
	while (str[i])
	{
		newstr[i] = f(str[i]);
		i++;
	}
	return (newstr);
}
