/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_modes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 10:44:37 by jbrisset          #+#    #+#             */
/*   Updated: 2020/10/07 10:44:39 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	md_type(mode_t mode)
{
	if ((mode & S_IFMT) == S_IFDIR)
		return ('d');
	else if ((mode & S_IFMT) == S_IFCHR)
		return ('c');
	else if ((mode & S_IFMT) == S_IFBLK)
		return ('b');
	else if ((mode & S_IFMT) == S_IFREG)
		return ('-');
	else if ((mode & S_IFMT) == S_IFLNK)
		return ('l');
	else if ((mode & S_IFMT) == S_IFSOCK)
		return ('s');
	else if ((mode & S_IFMT) == S_IFIFO)
		return ('p');
	else
		return ('?');
}

char	*md_usr(mode_t mode, char *p)
{
	if (mode & S_IRUSR)
		*p++ = 'r';
	else
		*p++ = '-';
	if (mode & S_IWUSR)
		*p++ = 'w';
	else
		*p++ = '-';
	if ((mode & (S_IXUSR | S_ISUID)) == 0)
		*p++ = '-';
	else if ((mode & (S_IXUSR | S_ISUID)) == S_IXUSR)
		*p++ = 'x';
	else if ((mode & (S_IXUSR | S_ISUID)) == S_ISUID)
		*p++ = 'S';
	else if ((mode & (S_IXUSR | S_ISUID)) == (S_IXUSR | S_ISUID))
		*p++ = 's';
	return (p);
}

char	*md_grp(mode_t mode, char *p)
{
	if (mode & S_IRGRP)
		*p++ = 'r';
	else
		*p++ = '-';
	if (mode & S_IWGRP)
		*p++ = 'w';
	else
		*p++ = '-';
	if ((mode & (S_IXGRP | S_ISGID)) == 0)
		*p++ = '-';
	else if ((mode & (S_IXGRP | S_ISGID)) == S_IXGRP)
		*p++ = 'x';
	else if ((mode & (S_IXGRP | S_ISGID)) == S_ISGID)
		*p++ = 'S';
	else if ((mode & (S_IXGRP | S_ISGID)) == (S_IXGRP | S_ISGID))
		*p++ = 's';
	return (p);
}

char	*md_other(mode_t mode, char *p)
{
	if (mode & S_IROTH)
		*p++ = 'r';
	else
		*p++ = '-';
	if (mode & S_IWOTH)
		*p++ = 'w';
	else
		*p++ = '-';
	if ((mode & (S_IXOTH | S_ISVTX)) == 0)
		*p++ = '-';
	else if ((mode & (S_IXOTH | S_ISVTX)) == S_IXOTH)
		*p++ = 'x';
	else if ((mode & (S_IXOTH | S_ISVTX)) == S_ISVTX)
		*p++ = 'T';
	else if ((mode & (S_IXOTH | S_ISVTX)) == (S_IXOTH | S_ISVTX))
		*p++ = 't';
	*p = '\0';
	return (p);
}

void	md_to_str(mode_t mode, char *p)
{
	*p++ = md_type(mode);
	p = md_usr(mode, p);
	p = md_grp(mode, p);
	p = md_other(mode, p);
}
