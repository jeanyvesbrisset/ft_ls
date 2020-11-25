/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:30:18 by jbrisset          #+#    #+#             */
/*   Updated: 2019/03/22 08:48:31 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_chars_ret(int nb, t_struct *t, char c)
{
	while (nb > 0)
	{
		ft_putchar(c);
		t->ret++;
		nb--;
	}
}

void		putstr_ret(char const *str, t_struct *t)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (t->lower)
			ft_putchar(ft_tolower(str[i]));
		else
			ft_putchar(str[i]);
		t->ret++;
		i++;
	}
}

u_int64_t	get_unsigned_argument(t_struct *t, va_list args)
{
	unsigned long long	res;

	if (t->length == hh)
		res = (unsigned char)va_arg(args, unsigned int);
	else if (t->length == h)
		res = (unsigned short int)va_arg(args, unsigned long long int);
	else if (t->length == l)
		res = va_arg(args, unsigned long int);
	else if (t->length == ll)
		res = va_arg(args, unsigned long long int);
	else
		res = va_arg(args, unsigned int);
	return (res);
}

int			get_len_base(long long res, t_struct *t)
{
	if (t->uns)
		return (ft_uintlen_base(res, t->base));
	else if (res < -9223372036854775807 && t->base == 10)
		return (19);
	else
		return (ft_intlen_base(ft_abs(res), t->base));
}

char		*get_itoa_base(long long res, t_struct *t)
{
	if (t->uns)
		return (ft_uitoa_base(res, t->base));
	else if (res < -9223372036854775807 && t->base == 10)
		return ("9223372036854775808");
	else
		return (ft_itoa_base(ft_abs(res), t->base));
}
