/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:30:18 by jbrisset          #+#    #+#             */
/*   Updated: 2019/03/22 09:25:35 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_result_dbl(t_struct *t, double f_res, int round_int)
{
	static char	res[1024];
	long long	i_nb;
	double		f_dec;
	int			i;
	int			intlen;

	i = 0;
	ft_bzero(res, 1024);
	if (!t->precision)
		f_res += 0.5;
	i_nb = f_res;
	if (round_int)
		i_nb++;
	f_dec = f_res - i_nb;
	intlen = ft_strlen(ft_itoa_base(i_nb, 10));
	ft_strcpy(res, ft_itoa_base(i_nb, 10));
	if (t->precision || t->sharp)
		res[intlen] = '.';
	round_fraction_double(&f_dec, t->precision);
	dbl_to_tab(&res, (++i + intlen), (t->precision + intlen), f_dec);
	if (error_in_rounding(&res))
		return (get_result_dbl(t, f_res, 1));
	return (res);
}

void	print_dbl(t_struct *t, double res)
{
	int		len;
	char	sign;

	len = 0;
	sign = (res < 0 ? MINUS : PLUS);
	len = ((sign == MINUS || t->plus) ? len + 1 : len);
	res = ((sign == MINUS) ? res * -1 : res);
	len += ft_strlen(get_result_dbl(t, res, 0));
	if (t->width > len)
	{
		if (!t->zero)
			put_chars_ret(t->width - len, t, BLANK);
		if (sign == MINUS || t->plus)
			put_chars_ret(1, t, sign);
		if (t->zero)
			put_chars_ret(t->width - len, t, ZERO);
	}
	else
	{
		if (sign == MINUS || t->plus)
			put_chars_ret(1, t, sign);
		else if (t->space)
			put_chars_ret(1, t, BLANK);
	}
	putstr_ret(get_result_dbl(t, res, 0), t);
}

void	print_dbl_left(t_struct *t, double res)
{
	int		len;
	char	sign;
	double	res_init;

	res_init = res;
	len = 0;
	sign = (res < 0 ? MINUS : PLUS);
	len = ((sign == MINUS || t->plus) ? len + 1 : len);
	res = ((sign == MINUS) ? res * -1 : res);
	len += ft_strlen(get_result_dbl(t, res, 0));
	if (t->width > len)
	{
		if (sign == MINUS || (sign == PLUS && t->plus))
			put_chars_ret(1, t, sign);
		putstr_ret(get_result_dbl(t, res, 0), t);
		put_chars_ret(t->width - len, t, BLANK);
	}
	else
		print_dbl(t, res_init);
}

void	manage_float(t_struct *t, va_list args)
{
	double		res;
	long double	ldbl;

	if (!t->got_precision)
		t->precision = 6;
	if (t->length == L)
	{
		ldbl = va_arg(args, long double);
		print_long_double(t, ldbl);
	}
	else
	{
		res = va_arg(args, double);
		if ((res < 0 && t->space) || (t->plus && t->space))
			t->space = 0;
		if (!t->minus)
			print_dbl(t, res);
		else
			print_dbl_left(t, res);
	}
}
