/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_more.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:31:08 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/09 14:22:49 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(t_pslist *head)
{
	while (head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}

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
	return (greatest);
}

int	size_list(t_pslist *head)
{
	int	size;

	if (!head)
		return (0);
	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}

void	find_greaters(t_pslist *head)
{
	t_pslist	*node;

	if (!head)
		return ;
	head->greaters = 0;
	node = head;
	while (node)
	{
		if (node->data > head->data)
			head->greaters++;
		node = node->next;
	}
}