/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:54:00 by jbrisset          #+#    #+#             */
/*   Updated: 2019/03/22 10:52:24 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_uint(t_struct *t, va_list args)
{
	unsigned long long	res;

	t->uns = 1;
	t->plus = 0;
	t->space = 0;
	t->base = 10;
	res = get_unsigned_argument(t, args);
	print_decimal(t, res);
}
