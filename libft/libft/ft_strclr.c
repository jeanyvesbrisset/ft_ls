/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:09:13 by jbrisset          #+#    #+#             */
/*   Updated: 2018/11/17 16:05:23 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			str[i] = '\0';
			i++;
		}
	}
}
