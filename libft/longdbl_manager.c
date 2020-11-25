/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longdbl_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:30:18 by jbrisset          #+#    #+#             */
/*   Updated: 2019/03/22 10:30:37 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_result_ldbl(t_struct *t, long double f_res, int round_int)
{
	static char	res[1024];
	long double	f_dec;
	long long	i_nb;
	int			i;
	int			intlen;

	i = 0;
	ft_bzero(res, 1000);
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
	round_fraction_ldbl(&f_dec, t->precision);
	ldbl_to_tab(&res, (++i + intlen), (t->precision + intlen), f_dec);
	if (error_in_rounding(&res))
		return (get_result_ldbl(t, f_res, 1));
	return (res);
}

void	print_ldbl(t_struct *t, long double res)
{
	int		len;
	char	sign;

	len = 0;
	sign = (res < 0 ? MINUS : PLUS);
	len = ((sign == MINUS || t->plus) ? len + 1 : len);
	res = ((sign == MINUS) ? res * -1 : res);
	len += ft_strlen(get_result_ldbl(t, res, 0));
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
	putstr_ret(get_result_ldbl(t, res, 0), t);
}

void	print_ldbl_left(t_struct *t, long double res)
{
	int			len;
	char		sign;
	long double	res_init;

	res_init = res;
	len = 0;
	sign = (res < 0 ? MINUS : PLUS);
	len = ((sign == MINUS || t->plus) ? len + 1 : len);
	res = ((sign == MINUS) ? res * -1 : res);
	len += ft_strlen(get_result_ldbl(t, res, 0));
	if (t->width > len)
	{
		if (sign == '-' || (sign == '+' && t->plus))
			put_chars_ret(1, t, sign);
		putstr_ret(get_result_ldbl(t, res, 0), t);
		put_chars_ret(t->width - len, t, BLANK);
	}
	else
		print_ldbl(t, res_init);
}

void	print_long_double(t_struct *t, long double res)
{
	if (!t->got_precision)
		t->precision = 6;
	if ((res < 0 && t->space) || (t->plus && t->space))
		t->space = 0;
	if (!t->minus)
		print_ldbl(t, res);
	else
		print_ldbl_left(t, res);
}
