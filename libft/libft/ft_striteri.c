/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:38:26 by jbrisset          #+#    #+#             */
/*   Updated: 2018/11/17 16:08:11 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *str, void (*f)(unsigned int, char *c))
{
	int				i;
	unsigned int	index;

	i = 0;
	if (str && f)
	{
		while (str[i] != '\0')
		{
			index = (unsigned int)i;
			f(index, &str[i]);
			i++;
		}
	}
}
