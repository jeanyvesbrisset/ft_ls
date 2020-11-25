/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 10:44:37 by jbrisset          #+#    #+#             */
/*   Updated: 2020/10/07 10:44:39 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	init_data(t_data *data)
{
	data->flags.l = 0;
	data->flags.a = 0;
	data->flags.r = 0;
	data->flags.t = 0;
	data->flags.up_r = 0;
	data->flags.m = 0;
	data->flags.illegal = 0;
	data->file = NULL;
	data->notfnd = NULL;
	data->sort = 0;
}

int		is_hidden(t_file *file, t_data *data)
{
	char	*s;
	int		len;

	s = ft_strrchr(file->name, '/');
	if (!s)
		s = file->name;
	len = ft_strlen(s);
	if (s[1] == '.')
	{
		if (file->parent && (len == 2 || (len == 3 && s[2] == '.')
			|| (len > 3 && !data->flags.a)))
			return (1);
	}
	return (0);
}

int		is_lsable(t_file *file, t_data *data)
{
	if (!file || is_hidden(file, data) || file->type == DT_LNK || file->error)
		return (0);
	return (1);
}

int		ft_ls(t_data *data, t_file *curr)
{
	if (curr == data->file)
		print_fnoparent(curr, data->notfnd, data);
	if (is_lsable(curr, data))
	{
		open_dir(data, curr);
		sort(&curr->children, data->sort);
		if (print_children(curr, data))
			ft_putchar('\n');
		if (data->flags.up_r)
			ft_ls(data, curr->children);
		ft_ls(data, curr->next);
	}
	else
	{
		if (curr && curr->next)
			ft_ls(data, curr->next);
	}
	if (curr)
		free_file(curr);
	return (1);
}

int		main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	if (parse(argc, argv, &data))
	{
		get_sorting(&data);
		sort(&data.file, data.sort);
		ft_ls(&data, data.file);
	}
	return (1);
}
