/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:28:53 by jbrisset          #+#    #+#             */
/*   Updated: 2019/03/22 12:35:39 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	filler(t_struct *t, long long res, int zeros)
{
	putstr_ret("0X", t);
	if (t->width <= t->precision)
		print_decimal(t, res);
	else
		put_chars_ret(zeros, t, ZERO);
}

void	print_hex(t_struct *t, long long res, int zeros, int len)
{
	int fill;

	fill = t->width - len - 2;
	if (t->width > t->precision)
	{
		if (t->precision < len)
		{
			if (t->zero && !t->got_precision)
				filler(t, res, fill);
			else
			{
				put_chars_ret(fill, t, BLANK);
				putstr_ret("0X", t);
			}
		}
		else
		{
			put_chars_ret(fill - zeros, t, BLANK);
			filler(t, res, zeros);
		}
		putstr_ret(get_itoa_base(res, t), t);
	}
	else
		filler(t, res, zeros);
}

void	print_hex_left(t_struct *t, long long res, int zeros, int len)
{
	int	blanks;

	if (t->width > t->precision && t->width > len)
	{
		zeros = (zeros < 0) ? 0 : zeros;
		filler(t, res, zeros);
		putstr_ret(get_itoa_base(res, t), t);
		blanks = t->width - 2 - zeros - len;
		put_chars_ret(blanks, t, BLANK);
	}
	else
		print_hex(t, res, zeros, len);
}

void	manage_hexa(t_struct *t, va_list args)
{
	int					len;
	int					zeros;
	unsigned long long	res;

	t->plus = 0;
	t->space = 0;
	t->base = 16;
	t->uns = 1;
	res = get_unsigned_argument(t, args);
	len = ft_uintlen_base(res, t->base);
	zeros = t->precision - len;
	if (!res)
		t->sharp = 0;
	if (!t->sharp)
		print_decimal(t, res);
	else if (t->sharp && t->minus)
		print_hex_left(t, res, zeros, len);
	else
		print_hex(t, res, zeros, len);
}
