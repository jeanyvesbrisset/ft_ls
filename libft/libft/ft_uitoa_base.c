/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <jbrisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:37:41 by jbrisset          #+#    #+#             */
/*   Updated: 2019/03/22 11:04:03 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa_base(unsigned long long int nb, int base)
{
	static char s[1024];
	int			len;

	ft_bzero(s, 1024);
	len = ft_uintlen_base(nb, base);
	while (len)
	{
		if (nb % base < 10 || base <= 10)
			s[len - 1] = (nb % base) + '0';
		else
			s[len - 1] = (nb % base) + 'A' - 10;
		nb /= base;
		len--;
	}
	return (s);
}
