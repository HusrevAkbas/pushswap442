/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_more.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:31:08 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/05 14:07:04 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_second_greatest(t_pslist *head, t_pslist *greatest)
{
	t_pslist	*node;

	node = head;
	greatest->second_greatest = node;
	if (greatest == node)
		greatest->second_greatest = node->next;
	while (node)
	{
		if (node->data > greatest->second_greatest->data && node != greatest)
			greatest->second_greatest = node;
		node = node->next;
	}
	
}
t_pslist	*find_greatest(t_pslist *head)
{
	t_pslist	*greatest;
	t_pslist	*node;
	int			index;

	if (!head)
		return (NULL);
	index = 0;
	greatest = head;
	node = head->next;
	while (node)
	{
		index += 1;
		if (node->data > greatest->data)
		{
			greatest = node;
			greatest->index = index;
		}
		node = node->next;
	}
	find_second_greatest(head, greatest);
	return greatest;
}
t_pslist	*find_smallest_bt(t_pslist *head, t_pslist *greatest)
{
	t_pslist	*node;
	t_pslist	*smallest_bt;

	node = head;
	smallest_bt = NULL;
	if (greatest->index <= size_list(head))
	{
		while (node && node != greatest)
		{
			if (!smallest_bt || smallest_bt->data < node->data)
				smallest_bt = node;
			node = node->next;
		}
	}
	return	smallest_bt;
}
int	size_list(t_pslist *head)
{
	int	size;

	size = 0;
	while (head)
	{
		head = head->next;
		size++;
	}
	return (size);
}
