/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:54:00 by jbrisset          #+#    #+#             */
/*   Updated: 2019/03/22 10:35:21 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_o(t_struct *t, long long res)
{
	int len;
	int blanks;

	len = get_len_base(res, t);
	if (t->width > t->precision && t->width > len)
	{
		blanks = t->width - len - 1;
		if (res && !t->sharp)
			put_chars_ret(1, t, ZERO);
		put_chars_ret(blanks, t, BLANK);
		if (t->sharp)
			put_chars_ret(1, t, (!res ? BLANK : ZERO));
		putstr_ret(get_itoa_base(res, t), t);
	}
	else if (t->width < t->precision && t->precision > len)
	{
		put_chars_ret(t->precision - len, t, ZERO);
		putstr_ret(get_itoa_base(res, t), t);
	}
	else
	{
		put_chars_ret(1, t, ZERO);
		print_decimal(t, res);
	}
}

void	print_o_left(t_struct *t, long long res)
{
	int	len;
	int blanks;
	int zeros;

	len = get_len_base(res, t);
	if (t->width > t->precision && t->width > len)
	{
		put_chars_ret(1, t, ZERO);
		zeros = t->precision - len - 1;
		zeros = (zeros < 0) ? 0 : zeros;
		put_chars_ret(zeros, t, ZERO);
		putstr_ret(get_itoa_base(res, t), t);
		blanks = t->width - 1 - zeros - len;
		put_chars_ret(blanks, t, BLANK);
	}
	else
		print_o(t, res);
}

void	manage_octal(t_struct *t, va_list args)
{
	unsigned long long res;

	t->plus = 0;
	t->space = 0;
	t->base = 8;
	t->uns = 1;
	res = get_unsigned_argument(t, args);
	if (!t->sharp)
		print_decimal(t, res);
	else if (t->sharp && t->minus)
		print_o_left(t, res);
	else
		print_o(t, res);
}
