/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_more.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:31:08 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/03 18:09:37 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	node = head;
	greatest->second_greatest = node;
	if (greatest == node)
		greatest->second_greatest = node->next;
	while (node)
	{
		if (node->data > greatest->second_greatest->data && node->data != greatest->data)
			greatest->second_greatest = node;
		node = node->next;
	}
	return greatest;
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
