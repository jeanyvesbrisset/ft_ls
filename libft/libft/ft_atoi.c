/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:41:45 by jbrisset          #+#    #+#             */
/*   Updated: 2018/11/17 14:07:16 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoi(const char *str)
{
	int			i;
	long long	res;
	int			sign;
	int			start;

	i = 0;
	res = 0;
	sign = 1;
	start = 0;
	while (str[start] != '\0' && (str[start] == ' ' || str[start] == '\t' ||
			str[start] == '\n' || str[start] == '\v' || str[start] == '\r' ||
			str[start] == '\b' || str[start] == '\f'))
		start++;
	i = start;
	while ((str[i] >= '0' && str[i] <= '9')
		|| ((str[i] == '-' || str[i] == '+') && i == start))
	{
		if (str[i] == '-')
			sign = -1;
		else if (str[i] >= '0' && str[i] <= '9')
			res = (res * 10) + (str[i] - 48);
		i++;
	}
	return ((res * sign));
}
