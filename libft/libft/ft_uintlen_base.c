/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:08:25 by jbrisset          #+#    #+#             */
/*   Updated: 2019/03/22 11:05:05 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_uintlen_base(unsigned long long n, unsigned long long base)
{
	unsigned long long int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n)
	{
		n = n / base;
		len++;
	}
	return (len);
}
