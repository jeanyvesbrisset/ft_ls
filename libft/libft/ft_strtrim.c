/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:45:54 by jbrisset          #+#    #+#             */
/*   Updated: 2018/11/17 16:19:49 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_c(char const *str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(str);
	j = len - 1;
	while ((str[i] == '\t' || str[i] == '\n' || str[i] == ' ') &&
		str[i] != '\0')
		i++;
	if (i == len)
		return (1);
	while (j > 0 && (str[j] == '\t' || str[j] == ' ' || str[j] == '\n'))
	{
		i++;
		j--;
	}
	return (len - i);
}

static int		get_start(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] == '\t' || str[i] == '\n' ||
							str[i] == ' '))
		i++;
	return (i);
}

char			*ft_strtrim(char const *str)
{
	int		i;
	int		char_nb;
	int		j;
	char	*result;
	char	*string;

	if (!str)
		return (NULL);
	string = (char *)str;
	i = get_start(string);
	char_nb = count_c(str);
	result = (char *)malloc(sizeof(char) * (char_nb + 1));
	if (result)
	{
		j = 0;
		while (j < char_nb)
		{
			result[j] = string[i];
			i++;
			j++;
		}
		result[j] = '\0';
	}
	return (result);
}
