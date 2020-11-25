/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 10:44:37 by jbrisset          #+#    #+#             */
/*   Updated: 2020/10/07 10:44:39 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	handle_datetime(time_t tt_dt, char res[13])
{
	time_t		now;
	char		dt_year[5];
	char		*dt;

	dt = ctime(&tt_dt);
	now = time(NULL);
	ft_strncpy(&res[0], &dt[8], 2);
	res[2] = ' ';
	res[3] = ft_tolower(dt[4]);
	res[4] = dt[5];
	res[5] = dt[6];
	res[6] = ' ';
	res[7] = ' ';
	ft_strncpy(dt_year, &dt[20], 4);
	if (tt_dt < (now - 15780000) || tt_dt > (now + 3600))
		ft_strncpy(&res[8], &dt[20], 4);
	else
		ft_strncpy(&res[7], &dt[11], 5);
	res[12] = '\0';
}

void	print_child_long(t_file *child, char *name)
{
	char	dt[13];

	handle_datetime(child->datetime, dt);
	if (child->sizedev == -1)
		ft_printf("%s  %2d %6s %6s %8lld %s %s", child->md, child->num,
		child->user, child->group, child->size, dt, name);
	else
		ft_printf("%s  %2d %6s %6s %3lld, %2lld %s %s", child->md, child->num,
		child->user, child->group, child->size, child->sizedev, dt, name);
	if (child->type == DT_LNK)
		ft_printf(" -> %s", child->smlnk);
	if (child->next)
		ft_putchar('\n');
}

int		print_child(char *name, t_file *child, t_data *data)
{
	if (data->flags.l)
	{
		if (child->error)
			ft_printf("ft_ls: %s: %s\n", child->name, child->error);
		else
			print_child_long(child, name);
	}
	else
	{
		ft_printf("%s", name);
		if (child->next)
		{
			if (data->flags.m)
				ft_putstr(", ");
			else
				ft_putstr("  ");
		}
	}
	return (1);
}

void	print_fnoparent(t_file *file, t_file *notfnd, t_data *data)
{
	int		print;
	t_file	*tmp;

	print = 0;
	if (notfnd)
	{
		sort(&notfnd, ALPHA);
		while (notfnd)
		{
			print = ft_printf("ft_ls: %s: %s", notfnd->name, notfnd->error);
			if (notfnd->next || file)
				ft_putchar('\n');
			tmp = notfnd;
			notfnd = notfnd->next;
			free_file(tmp);
		}
	}
	while (file)
	{
		if (file->type != DT_DIR)
			print = print_child(file->name, file, data);
		file = file->next;
	}
	if (print)
		ft_putchar('\n');
}

int		print_children(t_file *file, t_data *data)
{
	t_file	*child;
	t_file	*tmp;
	int		len_path;
	char	*file_no_path;
	int		print;

	print = 0;
	if (!file)
		return (print);
	child = file->children;
	len_path = ft_strlen(file->name) + 1;
	while (child)
	{
		file_no_path = &(child->name)[len_path];
		if (file_no_path[0] != '.' || data->flags.a)
			print += print_child(file_no_path, child, data);
		tmp = child;
		child = child->next;
		if (!data->flags.up_r)
			free_file(tmp);
		if (child)
			child->prev = NULL;
	}
	return (print);
}
