/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:00:15 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/15 12:46:31 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_last(t_pslist *head)
{
	t_pslist	*node;

	if (!head)
		return ;
	node = head;
	while (node->next)
		node = node->next;
	head->last = node;
}

void	swap(t_pslist **head, int print_msg)
{
	t_pslist	*fst;
	t_pslist	*sec;

	if (!head || !(*head) || !((*head)->next))
		return ;
	fst = *head;
	sec = fst->next;
	fst->next = sec->next;
	sec->next = fst;
	*head = sec;
	if (print_msg)
	{
		if ((*head)->name == 'A')
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
}

void	rotate(t_pslist **head, int print_msg)
{
	t_pslist	*fst;
	t_pslist	*sec;

	if (!head || !(*head) || !(*head)->next)
		return ;
	fst = *head;
	sec = (*head)->next;
	*head = sec;
	while (sec->next)
		sec = sec->next;
	sec->next = fst;
	fst->next = NULL;
	find_last(*head);
	if (print_msg)
	{
		if ((*head)->name == 'A')
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
}

void	reverse_rotate(t_pslist **head, int print_msg)
{
	t_pslist	*last;
	t_pslist	*sec_last;
	t_pslist	*fst;

	if (!head || !*head || !(*head)->next || !(*head)->next->next)
		return ;
	fst = *head;
	sec_last = NULL;
	if (fst->next->next)
		sec_last = fst;
	while (sec_last->next->next)
		sec_last = sec_last->next;
	last = sec_last->next;
	last->next = fst;
	sec_last->next = NULL;
	*head = last;
	(*head)->last = sec_last;
	if (print_msg)
	{
		if ((*head)->name == 'A')
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
}

void	push(t_pslist **src, t_pslist **dest, int print_msg)
{
	t_pslist	*src_fst;
	char		stack_name;

	if (!src || !dest || !(*src))
		return ;
	stack_name = (*dest)->name;
	if ((*dest)->name == 'C')
	{
		free(*dest);
		*dest = NULL;
		stack_name = 'B';
	}
	src_fst = *src;
	*src = (*src)->next;
	src_fst->next = *dest;
	*dest = src_fst;
	src_fst->name = stack_name;
	find_last(*src);
	find_last(*dest);
	if (print_msg)
		ft_printf("p%c\n", ft_tolower(src_fst->name));
}
