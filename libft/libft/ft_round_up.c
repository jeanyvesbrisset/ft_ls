/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 11:57:06 by jbrisset          #+#    #+#             */
/*   Updated: 2019/02/28 11:58:26 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_round_up(float nb)
{
	int		tmp_int;
	int		tmp_fl;
	float	delta;

	tmp_int = nb;
	tmp_fl = tmp_int;
	delta = nb - tmp_fl;
	if (delta > 0)
		tmp_int += 1;
	return (tmp_int);
}
