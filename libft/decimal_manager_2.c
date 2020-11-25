/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_manager_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:30:18 by jbrisset          #+#    #+#             */
/*   Updated: 2019/03/22 12:36:22 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_sign(t_struct *t, long long res)
{
	char	sign;

	if (t->uns)
		sign = 0;
	else if (res < 0 && t->base == 10)
		sign = MINUS;
	else if (t->space && !t->plus && res >= 0)
		sign = BLANK;
	else if ((t->plus || (t->plus && t->space)) && res >= 0 && t->base == 10)
		sign = PLUS;
	else
		sign = 0;
	if (sign)
		put_chars_ret(1, t, sign);
}

void	zero_manager(t_struct *t, long long res)
{
	if (t->got_precision && !t->precision && !t->space && !t->plus && !t->width)
		putstr_ret("", t);
	else if (t->got_precision && !t->precision && t->plus)
	{
		if (t->width)
		{
			if (t->minus)
				put_chars_ret(1, t, PLUS);
			put_chars_ret(t->width - t->plus, t, BLANK);
			if (!t->minus)
				put_chars_ret(1, t, PLUS);
		}
		else
			put_chars_ret(1, t, PLUS);
	}
	else if (t->got_precision && !t->precision)
	{
		if (t->width)
			put_chars_ret(t->width, t, BLANK);
		else
			put_chars_ret(1, t, BLANK);
	}
	else
		print_d(t, res);
}

void	put_zero_flag(t_struct *t, long long res)
{
	int			len;
	int			zeros;
	t_struct	tmp;

	tmp = (*t);
	len = get_len_base(res, t);
	if (res < 0 && !t->uns)
		len++;
	if (t->plus && res < 0)
		tmp.plus = 0;
	if (t->zero && t->minus)
		t->zero = 0;
	if (t->zero && t->got_precision)
		t->zero = 0;
	if (t->zero && len < t->width)
	{
		if (t->plus || res < 0)
			zeros = t->width - len - tmp.plus;
		else
			zeros = t->width - len - t->space;
		put_chars_ret(zeros, t, ZERO);
	}
}

void	put_zero_precision(t_struct *t, long long res)
{
	int	len;

	len = get_len_base(res, t);
	if (len < t->precision)
	{
		if (!t->minus)
			t->width = 0;
		put_chars_ret(t->precision - len, t, ZERO);
	}
}
