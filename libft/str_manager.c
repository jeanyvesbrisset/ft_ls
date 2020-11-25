/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:47:07 by jbrisset          #+#    #+#             */
/*   Updated: 2019/03/22 10:36:51 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_strings_ret(int len, t_struct *t, char *str)
{
	if (t->precision > 0 && t->precision < len)
	{
		len = t->precision;
		while (len--)
			put_chars_ret(1, t, *str++);
	}
	else
	{
		while (*str)
			put_chars_ret(1, t, *str++);
	}
}

void	precision_zero(t_struct *t)
{
	if (t->width && t->minus)
		put_chars_ret(t->width, t, BLANK);
	else if (t->width && !t->minus)
	{
		if (t->zero)
			put_chars_ret(t->width, t, ZERO);
		else
			put_chars_ret(t->width, t, BLANK);
	}
	ft_putstr("");
}

void	print_s_left(t_struct *t, char *res)
{
	int blanks;
	int len;

	len = ft_strlen(res);
	blanks = (t->precision && t->precision < len ?
	t->width - t->precision : t->width - len);
	if (!t->precision && t->got_precision)
		precision_zero(t);
	else
	{
		put_strings_ret(len, t, res);
		if (blanks > 0)
			put_chars_ret(blanks, t, BLANK);
	}
}

void	print_s(t_struct *t, char *res)
{
	int len;
	int padding;

	len = ft_strlen(res);
	padding = (t->precision && t->precision < len ?
	t->width - t->precision : t->width - len);
	if (!t->precision && t->got_precision)
		precision_zero(t);
	else
	{
		if (padding > 0)
		{
			if (t->zero)
				put_chars_ret(padding, t, ZERO);
			else
				put_chars_ret(padding, t, BLANK);
		}
		put_strings_ret(len, t, res);
	}
}

void	manage_str(t_struct *t, va_list args)
{
	char *res;

	res = va_arg(args, char*);
	if (!res)
	{
		if (t->minus)
			print_s_left(t, "(null)");
		else
			print_s(t, "(null)");
	}
	else if (t->minus)
		print_s_left(t, res);
	else
		print_s(t, res);
}
