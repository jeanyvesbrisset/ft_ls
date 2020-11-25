/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 10:44:37 by jbrisset          #+#    #+#             */
/*   Updated: 2020/10/07 10:44:39 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int	scan_flag(char f, t_data *data)
{
	if (f == 'l' || f == 'a' || f == 'r' || f == 't' || f == 'R' || f == 'm')
	{
		if (f == 'l')
			data->flags.l = 1;
		else if (f == 'm')
		{
			data->flags.m = 1;
			if (data->flags.l)
				data->flags.l = 0;
		}
		else if (f == 'a')
			data->flags.a = 1;
		else if (f == 'r')
			data->flags.r = 1;
		else if (f == 't')
			data->flags.t = 1;
		else if (f == 'R')
			data->flags.up_r = 1;
		return (1);
	}
	else
		data->flags.illegal = f;
	return (0);
}

int	parse_flag(char *flag, t_data *data)
{
	int	i;

	i = 1;
	while (flag[i])
	{
		if (!scan_flag(flag[i], data))
			return (0);
		i++;
	}
	return (1);
}
