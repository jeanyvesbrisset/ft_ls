/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 10:44:37 by jbrisset          #+#    #+#             */
/*   Updated: 2020/10/07 10:44:39 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int	handle_illegal_flag(char illegal)
{
	ft_printf("ft_ls: illegal option -- %c\n", illegal);
	ft_printf("usage: ft_ls [-lartRm] [file ...]");
	return (0);
}

int	get_type(struct stat buffer)
{
	if (S_ISREG(buffer.st_mode))
		return (DT_REG);
	if (S_ISDIR(buffer.st_mode))
		return (DT_DIR);
	if (S_ISCHR(buffer.st_mode))
		return (DT_CHR);
	if (S_ISBLK(buffer.st_mode))
		return (DT_BLK);
	if (S_ISFIFO(buffer.st_mode))
		return (DT_FIFO);
	if (S_ISLNK(buffer.st_mode))
		return (DT_LNK);
	if (S_ISSOCK(buffer.st_mode))
		return (DT_SOCK);
	return (-1);
}

int	file_exists(t_file *file)
{
	struct stat	buf;

	if (lstat(file->name, &buf) < 0)
	{
		file->error = strerror(errno);
		return (0);
	}
	file->mtime = buf.st_mtimespec;
	file->type = get_type(buf);
	file->size = buf.st_size;
	return (1);
}

int	parse_dir(char *arg, t_data *data)
{
	t_file	*new;

	new = new_file(arg);
	if (file_exists(new))
	{
		if (data->flags.l || data->flags.t)
			fill_info(new, NULL);
		push_file(&data->file, new);
	}
	else
		push_file(&data->notfnd, new);
	return (1);
}

int	parse(int argc, char **argv, t_data *data)
{
	int	i;
	int	flag_done;

	flag_done = 0;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && !flag_done)
		{
			if (!parse_flag(argv[i], data))
				return (handle_illegal_flag(data->flags.illegal));
		}
		else
		{
			parse_dir(argv[i], data);
			flag_done = 1;
		}
		i++;
	}
	if (!flag_done)
		return (parse_dir(".", data));
	return (1);
}
