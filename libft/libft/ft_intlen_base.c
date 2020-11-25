/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 11:57:06 by jbrisset          #+#    #+#             */
/*   Updated: 2019/02/28 11:58:26 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_intlen_base(long long int n, int base)
{
	int	len;

	len = 0;
	if (n < -9223372036854775807)
		return (19);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n = n / base;
		len++;
	}
	return (len);
}
