/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:17:34 by jbrisset          #+#    #+#             */
/*   Updated: 2019/02/22 15:18:05 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_length(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static int		is_negative(int nb)
{
	if (nb < 0)
		return (1);
	else
		return (0);
}

char			*ft_itoa(int nb)
{
	char	*result;
	int		len;
	long	n;

	n = nb;
	len = get_length(nb);
	result = ft_strnew(len);
	if (result)
	{
		if (is_negative(nb))
			n *= -1;
		result[len + 1] = '\0';
		while (len-- >= 0)
		{
			result[len] = (n % 10) + '0';
			n /= 10;
		}
		if (is_negative(nb))
			result[0] = '-';
	}
	return (result);
}
