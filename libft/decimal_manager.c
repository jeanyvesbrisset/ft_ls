/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:30:18 by jbrisset          #+#    #+#             */
/*   Updated: 2019/03/22 08:59:05 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_blank_left(t_struct *t, long long res)
{
	int			len;
	int			blanks;
	t_struct	tmp;

	blanks = 0;
	tmp = (*t);
	len = get_len_base(res, t);
	res < 0 && !t->uns ? len++ : len;
	if (t->space && (res < 0 || t->plus))
		tmp.space = 0;
	if (t->plus && res < 0)
		tmp.plus = 0;
	if (t->width > t->precision && t->precision >= len)
		blanks = (res < 0) ? t->width - t->precision - 1 - tmp.space :
		t->width - t->precision - tmp.space - tmp.plus;
	else if (t->width > len && t->zero)
	{
		if (t->got_precision && t->precision < len)
			blanks = t->width - len - tmp.space - tmp.plus;
	}
	else
		blanks = t->width - len - tmp.space - tmp.plus;
	if (t->precision >= t->width)
		blanks = 0;
	put_chars_ret(blanks, t, BLANK);
}

void	put_blank_right(t_struct *t, long long res)
{
	int			blanks;
	int			len;
	t_struct	tmp;

	tmp = (*t);
	if (t->space && (res < 0 || t->plus))
		tmp.space = 0;
	if (t->plus && res < 0)
		tmp.plus = 0;
	len = get_len_base(res, t);
	res < 0 && !t->uns ? len++ : len;
	if (t->width > t->precision)
	{
		if (len > t->precision)
			blanks = t->width - len - tmp.space - tmp.plus;
		else if (t->precision >= len && res < 0)
			blanks = t->width - t->precision - 1 - tmp.space - tmp.plus;
		else
			blanks = t->width - t->precision - tmp.space - tmp.plus;
	}
	else if (t->precision >= t->width)
		blanks = 0;
	else
		blanks = t->width - len - tmp.space - tmp.plus;
	put_chars_ret(blanks, t, BLANK);
}

void	print_d(t_struct *t, long long res)
{
	if (!t->minus)
		put_blank_left(t, res);
	put_sign(t, res);
	put_zero_flag(t, res);
	put_zero_precision(t, res);
	putstr_ret(get_itoa_base(res, t), t);
	if (t->minus)
		put_blank_right(t, res);
}

void	print_decimal(t_struct *t, long long res)
{
	if (res == 0)
		zero_manager(t, res);
	else
		print_d(t, res);
}

void	manage_decimal(t_struct *t, va_list args)
{
	long long int	res;

	if (t->length == hh)
		res = (signed char)va_arg(args, int);
	else if (t->length == h)
		res = (short int)va_arg(args, int);
	else if (t->length == l)
		res = va_arg(args, long int);
	else if (t->length == ll)
		res = va_arg(args, long long int);
	else
		res = va_arg(args, int);
	t->base = 10;
	print_decimal(t, res);
}
