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

void	handle_ugid(t_file *file, struct stat *buf)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(buf->st_uid);
	if (!pwd)
		file->error = strerror(errno);
	else
	{
		file->user = ft_strdup(pwd->pw_name);
		grp = getgrgid(buf->st_gid);
		if (!grp)
			file->error = strerror(errno);
		else
			file->group = ft_strdup(grp->gr_name);
	}
}

void	handle_modes(mode_t mode, t_file *file)
{
	char	chars[11];

	md_to_str(mode, chars);
	ft_strcpy(file->md, chars);
}

void	handle_size(t_file *file, struct stat *buf)
{
	long long int tmp;

	if (!(S_ISCHR(buf->st_mode)) && !(S_ISBLK(buf->st_mode)))
		file->size = buf->st_size;
	else
	{
		tmp = buf->st_rdev >> 24 & 0xff;
		file->size = tmp;
		tmp = buf->st_rdev & 0xffffff;
		file->sizedev = tmp;
	}
}

void	fill_info(t_file *file, struct dirent *dirent)
{
	struct stat	buf;
	int			err;

	err = lstat(file->name, &buf);
	if (err)
	{
		file->error = strerror(errno);
		return ;
	}
	if (dirent)
		file->type = dirent->d_type;
	if (file->type == DT_LNK)
	{
		file->smlnk = malloc(sizeof(char) * buf.st_size + 1);
		err = readlink(file->name, file->smlnk, buf.st_size);
		file->smlnk[buf.st_size] = '\0';
	}
	file->datetime = buf.st_mtime;
	file->num = buf.st_nlink;
	file->mtime = buf.st_mtimespec;
	if (file->parent)
		file->parent->blocks = file->parent->blocks + buf.st_blocks;
	handle_ugid(file, &buf);
	handle_modes(buf.st_mode, file);
	handle_size(file, &buf);
}
