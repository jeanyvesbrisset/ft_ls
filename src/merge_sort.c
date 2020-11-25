/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 10:44:37 by jbrisset          #+#    #+#             */
/*   Updated: 2020/10/07 10:44:39 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		get_cmp(t_file *first, t_file *second, int sort)
{
	if (sort == ALPHA)
		return (ft_strcmp(first->name, second->name) < 0);
	else if (sort == REVALPHA)
		return (ft_strcmp(first->name, second->name) > 0);
	else
	{
		if (first->mtime.tv_sec > second->mtime.tv_sec)
			return (sort == MTIME);
		else if (first->mtime.tv_sec < second->mtime.tv_sec)
			return (sort == REVMTIME);
		else
		{
			if (first->mtime.tv_nsec > second->mtime.tv_nsec)
				return (sort == MTIME);
			else
				return (sort == REVMTIME);
		}
	}
}

t_file	*split(t_file *head)
{
	t_file	*fast;
	t_file	*slow;
	t_file	*temp;

	fast = head;
	slow = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	temp = slow->next;
	slow->next = NULL;
	return (temp);
}

t_file	*merge(t_file *first, t_file *second, int sort)
{
	if (!first)
		return (second);
	if (!second)
		return (first);
	if (get_cmp(first, second, sort))
	{
		first->next = merge(first->next, second, sort);
		first->next->prev = first;
		first->prev = NULL;
		return (first);
	}
	else
	{
		second->next = merge(first, second->next, sort);
		second->next->prev = second;
		second->prev = NULL;
		return (second);
	}
}

t_file	*merge_sort(t_file *head, int sort)
{
	t_file	*second;

	if (!head || !head->next)
		return (head);
	second = split(head);
	head = merge_sort(head, sort);
	second = merge_sort(second, sort);
	return (merge(head, second, sort));
}
