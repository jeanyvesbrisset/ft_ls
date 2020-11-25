/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:01:28 by jbrisset          #+#    #+#             */
/*   Updated: 2019/01/24 14:42:55 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_line(int fd, char **line, char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	free(*line);
	if (str[fd][i] == '\0')
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	else if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		tmp = ft_strdup(&str[fd][i + 1]);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*str[1];
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*tmp;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (get_line(fd, line, str));
}
