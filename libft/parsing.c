/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:47:07 by jbrisset          #+#    #+#             */
/*   Updated: 2019/03/22 12:39:22 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_struct *t)
{
	t->minus = 0;
	t->plus = 0;
	t->space = 0;
	t->sharp = 0;
	t->got_precision = 0;
	t->precision = 0;
	t->zero = 0;
	t->width = 0;
	t->base = 0;
	t->length = none;
	t->lower = 0;
	t->uns = 0;
}

void	set_length(char const *format, t_struct *t)
{
	char	curr;
	char	next;

	curr = format[t->i];
	next = format[t->i + 1];
	if (curr == 'h')
	{
		if (next == 'h')
			t->length = hh;
		else
			t->length = h;
	}
	else if (curr == 'l')
	{
		if (next == 'l')
			t->length = ll;
		else
			t->length = l;
	}
	else if (curr == 'L')
		t->length = L;
	while (format[t->i] &&
		!(ft_strchr("diouxXscpf%%-+#.0123456789", format[t->i])))
		t->i++;
}

void	modif_handler(char const *f, t_struct *t)
{
	if (f[t->i] == ' ')
		t->space = 1;
	if (f[t->i] == '-')
		t->minus = 1;
	if (f[t->i] == '+')
		t->plus = 1;
	if (f[t->i] == '#')
		t->sharp = 1;
	if (f[t->i] == '.')
		t->got_precision = 1;
	if (f[t->i] == '0' && !t->got_precision)
		t->zero = 1;
	if (ft_isdigit(f[t->i]))
	{
		if (t->got_precision)
			t->precision = ft_atoi(&f[t->i]);
		else if (!(t->got_precision))
			t->width = ft_atoi(&f[t->i]);
		while (ft_isdigit(f[t->i + 1]))
			t->i++;
	}
	if (f[t->i] == 'h' || f[t->i] == 'l' || f[t->i] == 'L')
		set_length(f, t);
}

void	spec_handler(const char *format, t_struct *t, va_list args)
{
	if (format[t->i] == 'd' || format[t->i] == 'i')
		manage_decimal(t, args);
	if (format[t->i] == 'o')
		manage_octal(t, args);
	if (format[t->i] == 'u')
		manage_uint(t, args);
	if (format[t->i] == 'x' || format[t->i] == 'X')
	{
		t->lower = (format[t->i] == 'x' ? 1 : 0);
		manage_hexa(t, args);
	}
	if (format[t->i] == 'c')
		manage_char(t, args);
	if (format[t->i] == 's')
		manage_str(t, args);
	if (format[t->i] == 'f')
		manage_float(t, args);
	if (format[t->i] == 'p')
		manage_ptr(t, args);
	if (format[t->i] == '%')
		print_char(t, '%');
	t->parse = 0;
}

void	format_handler(const char *format, t_struct *t, va_list args)
{
	while (format[t->i])
	{
		while (format[t->i] == '%' && format[t->i])
		{
			t->parse = 1;
			init_struct(t);
			t->i++;
			while (format[t->i] && t->parse &&
				ft_strchr(" -+#.0123456789hlLdiouxXscpf%%", format[t->i]))
			{
				if (ft_strchr(" -+#.0123456789hlL", format[t->i]))
					modif_handler(format, t);
				if (ft_strchr("diouxXscpf%%", format[t->i]))
					spec_handler(format, t, args);
				t->i++;
			}
		}
		if (format[t->i] != '\0')
		{
			put_chars_ret(1, t, format[t->i]);
			t->i++;
		}
	}
}
