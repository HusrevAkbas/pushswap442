/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_more.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:31:08 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/03 14:36:28 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pslist	*find_greatest(t_pslist *head)
{
	t_pslist	*greatest;
	t_pslist	*second_greatest;

	head->index = 0;
	greatest = head;
	second_greatest = greatest;
	head = greatest->next;
	while (head)
	{
		head->index += 1;
		if (head->data > greatest->data)
		{
			second_greatest = greatest;
			greatest = head;
		}
		head = head->next;
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
