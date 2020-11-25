/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:30:18 by jbrisset          #+#    #+#             */
/*   Updated: 2019/03/22 08:49:35 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c_left(t_struct *t, char res)
{
	int blanks;

	blanks = t->width - 1;
	put_chars_ret(1, t, res);
	put_chars_ret(blanks, t, BLANK);
}

void	print_c(t_struct *t, char res)
{
	if (t->width > 1)
	{
		if (t->zero)
			put_chars_ret(t->width - 1, t, ZERO);
		else
			put_chars_ret(t->width - 1, t, BLANK);
	}
	put_chars_ret(1, t, res);
}

void	print_char(t_struct *t, int res)
{
	if (t->minus && t->width > 1)
		print_c_left(t, res);
	else
		print_c(t, res);
}

void	manage_char(t_struct *t, va_list args)
{
	int		res;

	res = va_arg(args, int);
	print_char(t, res);
}
