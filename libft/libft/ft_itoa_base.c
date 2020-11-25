/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:08:25 by jbrisset          #+#    #+#             */
/*   Updated: 2019/03/22 10:58:04 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** A function that converts an integer value to a null-terminated string using
** specified base and stores the result in a char array that must be allocated.
** We won't use malloc to prevent syscall from happening,
** we'll use a 1024 bytes long array instead.
*/

static void	fill_itoa_base(unsigned long long nb,
			unsigned long long base, char *s)
{
	int		len;

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
}

char		*ft_itoa_base(long long int nb, int base)
{
	static char	s[1024];

	ft_bzero(s, 1024);
	if (base == 10 && nb < 0)
	{
		if (nb < -9223372036854775807)
			ft_strcpy(s, "-9223372036854775808");
		else
		{
			s[0] = '-';
			fill_itoa_base(-nb, base, s + 1);
		}
	}
	else
		fill_itoa_base(nb, base, s);
	return (s);
}
