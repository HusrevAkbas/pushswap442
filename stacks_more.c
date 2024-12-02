/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_more.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:31:08 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/02 16:27:22 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pslist	*find_greatest(t_pslist *head)
{
	t_pslist	*greatest;
	t_pslist	*second_greatest;

	greatest = head;
	second_greatest = greatest;
	head = greatest->next;
	greatest->index = 0;
	while (head)
	{
		if (head->data > greatest->data)
		{
			second_greatest = greatest;
			greatest->index += 1;
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
