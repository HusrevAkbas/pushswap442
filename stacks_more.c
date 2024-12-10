/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_more.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:31:08 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/10 14:42:08 by huakbas          ###   ########.fr       */
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

t_pslist	*find_greatest(t_pslist *head)
{
	t_pslist	*greatest;
	t_pslist	*node;
	int			index;

	if (!head)
		return (NULL);
	if (!head->next)
		return (head);
	index = 0;
	greatest = head;
	node = head;
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
