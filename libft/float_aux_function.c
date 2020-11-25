/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_aux_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:30:18 by jbrisset          #+#    #+#             */
/*   Updated: 2019/03/22 12:38:16 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	round_fraction_double(double *f_dec, int precision)
{
	int i;

	i = 0;
	while (++i <= precision)
		*f_dec *= 10;
	*f_dec += 0.5;
	while (--i > 0)
		*f_dec /= 10;
}

void	dbl_to_tab(char (*res)[1024], int i, int p, double f)
{
	long long	nb;

	while (i <= p)
	{
		f *= 10;
		nb = f;
		f = (f - nb);
		(*res)[i] = nb + '0';
		i++;
	}
}

void	round_fraction_ldbl(long double *f_dec, int precision)
{
	int i;

	i = 0;
	while (++i <= precision)
		*f_dec *= 10;
	*f_dec += 0.5;
	while (--i > 0)
		*f_dec /= 10;
}

void	ldbl_to_tab(char (*r)[1024], int i, int p, long double f)
{
	long long	nb;

	while (i <= p)
	{
		f *= 10;
		nb = f;
		f = (f - nb);
		(*r)[i] = nb + '0';
		i++;
	}
}

int		error_in_rounding(char (*res)[1024])
{
	int	i;
	int	error;

	i = -1;
	error = 0;
	while ((*res)[++i])
	{
		if ((*res)[i] == ':')
			error++;
	}
	return (error);
}
