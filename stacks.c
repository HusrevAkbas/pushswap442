/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:26:54 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/07 17:26:17 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_rotate_a(t_pslist *head)
{
	t_pslist	*node;

	node = head;
	head->greaters = 0;
	while (node)
	{
		if (node->data > head->data)
			head->greaters++;
		node = node->next;
	}
	if (!head)
		return (0);
	if (head->greaters <= size_list(head) * 2 / 3 && size_list(head) != 3)
		return (1);
	if (size_list(head) == 3 && find_greatest(head) == head)
		return (1);
	return (0);
}

int	is_rotate_b(t_pslist *head)
{
	t_pslist	*node;

	node = head;
	head->smallers = 0;
	while (node)
	{
		if (node->data < head->data)
			head->smallers++;
		node = node->next;
	}
	if (!head || size_list(head) < 2)
		return (0);
	if (head->smallers <= size_list(head) * 2 / 3 && size_list(head) > 3)
		return (1);
	return (0);
}

int	is_swap_a(t_pslist *head)
{
	if (!head || !head->next)
		return (0);
	if (head->data > head->next->data)
		return (1);
	return (0);
}

int	is_swap_b(t_pslist *head)
{
	if (!head || !head->next)
		return (0);
	if (head->data < head->next->data)
		return (1);
	return (0);
}

t_pslist	*set_list(char **args)
{
	t_pslist	*list;
	t_pslist	*next;
	t_pslist	*new;
	int			i;

	if (!args || !args[0])
		return (NULL);
	list = new_list(ft_atoi(args[0]));
	if (!list)
		return (NULL);
	list->name = 'A';
	next = list;
	i = 1;
	while (args[i])
	{
		new = new_list(ft_atoi(args[i]));
		if (!new)
			return (clear_list(list, NULL));
		new->name = 'A';
		next->next = new;
		next = new;
		i++;
	}
	return (list);
}
