/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 10:44:37 by jbrisset          #+#    #+#             */
/*   Updated: 2020/10/07 10:44:39 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	get_sorting(t_data *data)
{
	if (data->flags.r && !data->flags.t)
		data->sort = REVALPHA;
	else if (!data->flags.r && data->flags.t)
		data->sort = MTIME;
	else if (data->flags.r && data->flags.t)
		data->sort = REVMTIME;
	else
		data->sort = ALPHA;
}

void	sort(t_file **head, int sort_type)
{
	if (!*head)
		return ;
	*head = merge_sort(*head, sort_type);
}

int		empty_or_dot(t_file *file)
{
	char	*file_no_path;
	t_file	*child;
	int		len_path;

	if (!file || !file->children)
		return (0);
	child = file->children;
	len_path = ft_strlen(file->name) + 1;
	while (child)
	{
		file_no_path = &(child->name)[len_path];
		if (file_no_path[0] != '.')
			return (0);
		child = child->next;
	}
	return (1);
}

int		handle_opendir_err(char *name)
{
	if (errno != 20)
	{
		ft_printf("\n%s:\nft_ls: %s: ", name, name);
		perror("");
	}
	return (0);
}

int		open_dir(t_data *data, t_file *curr)
{
	struct dirent	*dirent;
	DIR				*dir;
	t_file			*new;

	dir = opendir(curr->name);
	if (!dir)
		return (handle_opendir_err(curr->name));
	ft_printf("\n%s:\n", curr->name);
	while ((dirent = readdir(dir)) != NULL)
	{
		new = new_child(curr, dirent->d_name);
		if (data->flags.l || data->flags.t)
			fill_info(new, dirent);
		push_file(&curr->children, new);
	}
	closedir(dir);
	if ((data->flags.l && curr->type == DT_DIR) &&
		((empty_or_dot(curr) && data->flags.a) || !empty_or_dot(curr)))
		ft_printf("total %d\n", curr->blocks);
	return (1);
}
