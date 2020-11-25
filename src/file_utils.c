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

t_file	*new_file(char *name)
{
	t_file *new;

	new = malloc(sizeof(t_file));
	new->name = ft_strdup(name);
	new->parent = NULL;
	new->children = NULL;
	new->error = NULL;
	new->size = 0;
	new->sizedev = -1;
	new->type = 0;
	new->blocks = 0;
	new->smlnk = NULL;
	new->user = NULL;
	new->group = NULL;
	new->datetime = 0;
	new->prev = NULL;
	new->next = NULL;
	new->mtime.tv_nsec = 0;
	new->mtime.tv_sec = 0;
	return (new);
}

t_file	*new_child(t_file *parent, char *child_name)
{
	t_file	*new;
	char	*fullname;
	char	*path;

	path = ft_strjoin(parent->name, "/");
	fullname = ft_strjoin(path, child_name);
	new = new_file(fullname);
	new->parent = parent;
	free(path);
	free(fullname);
	return (new);
}

void	queue_file(t_file *head, t_file *node)
{
	t_file *curr;
	t_file *prev;

	curr = head;
	prev = curr;
	if (head == NULL)
		head = node;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	curr->next = node;
	node->prev = prev;
	node->next = NULL;
}

void	push_file(t_file **head, t_file *node)
{
	if (*head == NULL)
		*head = node;
	else if (node)
	{
		node->next = *head;
		(*head)->prev = node;
		*head = node;
	}
}

void	free_file(t_file *file)
{
	free(file->name);
	if (file->user)
		free(file->user);
	if (file->group)
		free(file->group);
	if (file->smlnk)
		free(file->smlnk);
	free(file);
}
