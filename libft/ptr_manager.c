/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:30:18 by jbrisset          #+#    #+#             */
/*   Updated: 2019/03/22 13:57:39 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_addr(unsigned long long res)
{
	char			*base;
	static char		addr[1000];
	char			final[1000];
	int				i;
	int				j;

	res = (unsigned long long)res;
	ft_bzero(addr, 1000);
	ft_bzero(final, 1000);
	base = "0123456789abcdef";
	i = 999;
	if (res > 15)
	{
		while ((unsigned long long)res / 16 > 0)
		{
			final[i--] = base[((unsigned long long)res % 16)];
			res = (unsigned long long)res / 16;
		}
	}
	final[i] = base[((unsigned long long)res % 16)];
	j = 0;
	while (i < 1000)
		addr[j++] = final[i++];
	return ((char*)addr);
}

void	print_p(t_struct *t, void *res)
{
	int	len;
	int	blanks;
	int	zeros;

	len = ft_strlen(get_addr((unsigned long long)res)) + 2;
	zeros = (t->got_precision) ? t->precision - (len - 2) : 0;
	if (t->width > zeros + 2)
	{
		if (t->width > t->precision && t->precision > (len - 2))
			blanks = t->width - (zeros + len);
		else
			blanks = t->width - len;
		put_chars_ret(blanks, t, BLANK);
	}
	put_chars_ret(1, t, '0');
	put_chars_ret(1, t, 'x');
	if (t->precision > (len - 2))
		put_chars_ret(zeros, t, ZERO);
	putstr_ret(get_addr((unsigned long long)res), t);
}

void	print_p_left(t_struct *t, void *res)
{
	int	len;
	int	blanks;
	int	zeros;

	len = ft_strlen(get_addr((unsigned long long)res)) + 2;
	if (t->width > len)
	{
		put_chars_ret(1, t, '0');
		put_chars_ret(1, t, 'x');
		zeros = (t->got_precision) ? t->precision - (len - 2) : 0;
		if (t->precision > (len - 2))
			put_chars_ret(zeros, t, ZERO);
		putstr_ret(get_addr((unsigned long long)res), t);
		blanks = t->width - (zeros + len);
		put_chars_ret(blanks, t, BLANK);
	}
	else
		print_p(t, res);
}

void	print_ptr(t_struct *t, void *res)
{
	if (t->sharp)
		t->sharp = 0;
	if (t->minus)
		print_p_left(t, res);
	else
		print_p(t, res);
}

void	manage_ptr(t_struct *t, va_list args)
{
	void	*res;

	res = va_arg(args, void*);
	print_ptr(t, res);
}
