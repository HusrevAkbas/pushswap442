/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:00:05 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/15 12:59:08 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_pslist **list_a, t_pslist **list_b, int print_msg)
{
	swap(list_a, 0);
	swap(list_b, 0);
	if (print_msg)
		write(1, "ss\n", 3);
}

void	rotate_both(t_pslist **list_a, t_pslist **list_b, int print_msg)
{
	rotate(list_a, 0);
	rotate(list_b, 0);
	if (print_msg)
		write(1, "rr\n", 3);
}

void	reverse_rotate_both(t_pslist **list_a, t_pslist **list_b, int print_msg)
{
	reverse_rotate(list_a, 0);
	reverse_rotate(list_b, 0);
	if (print_msg)
		write(1, "rrr\n", 4);
}

t_pslist	*find_smallest(t_pslist *head)
{
	t_pslist	*node;
	t_pslist	*small;

	if (!head)
		return (NULL);
	node = head;
	small = head;
	while (node->next)
	{
		if (node->data < small->data)
			small = node;
		node = node->next;
	}
	return (small);
}
