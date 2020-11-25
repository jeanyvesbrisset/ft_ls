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

#ifndef FT_LS_H
# define FT_LS_H

# define ALPHA 1
# define REVALPHA 2
# define MTIME 3
# define REVMTIME 4

# include "libft/ft_printf.h"
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>

typedef struct	s_flags
{
	int		l;
	int		a;
	int		r;
	int		t;
	int		up_r;
	int		m;
	char	illegal;
}				t_flags;

typedef struct	s_file
{
	char			*name;
	int				type;
	struct s_file	*parent;
	struct s_file	*children;
	struct timespec	mtime;
	long long int	size;
	long long int	sizedev;
	int				blocks;
	char			md[11];
	int				num;
	char			*smlnk;
	char			*user;
	char			*group;
	time_t			datetime;
	char			*error;
	struct s_file	*prev;
	struct s_file	*next;
}				t_file;

typedef struct	s_data
{
	t_file	*file;
	t_file	*notfnd;
	t_flags	flags;
	t_file	*list;
	int		sort;
}				t_data;

int				parse(int argc, char **argv, t_data *data);
int				parse_flag(char *flag, t_data *data);
void			get_sorting(t_data *data);
int				open_dir(t_data *data, t_file *curr);
void			sort(t_file **head, int sort_type);
t_file			*merge_sort(t_file *head, int sort);
void			fill_info(t_file *file, struct dirent *dirent);
void			md_to_str(mode_t mode, char *p);
int				print_children(t_file *file, t_data *data);
void			print_fnoparent(t_file *file, t_file *notfnd, t_data *data);
t_file			*new_file(char *name);
t_file			*new_child(t_file *parent, char *child_name);
void			queue_file(t_file *head, t_file *node);
void			push_file(t_file **head, t_file *node);
void			free_file(t_file *file);

#endif
