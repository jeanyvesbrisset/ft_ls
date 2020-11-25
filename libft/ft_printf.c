/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:30:18 by jbrisset          #+#    #+#             */
/*   Updated: 2019/03/22 08:59:05 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_struct	t;
	va_list		args;

	t.i = 0;
	t.ret = 0;
	t.parse = 0;
	va_start(args, format);
	format_handler(format, &t, args);
	va_end(args);
	return (t.ret);
}
