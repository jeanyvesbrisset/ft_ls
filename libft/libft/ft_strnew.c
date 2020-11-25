/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:41:52 by jbrisset          #+#    #+#             */
/*   Updated: 2018/11/17 14:10:06 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	int		sz;
	char	*new;

	sz = (int)size;
	new = (char *)malloc((sz + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_bzero(new, sz + 1);
	return (new);
}
