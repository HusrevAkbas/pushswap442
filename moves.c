/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:00:15 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/05 14:08:58 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		else if ((*head)->name == 'B')
			write(1, "sb\n", 3);
		else
			write(1, "Error in moves.c:swap\n", 22);
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
	(*head)->last = fst;
	if (print_msg)
	{
		if ((*head)->name == 'A')
			write(1, "ra\n", 3);
		else if ((*head)->name == 'B')
			write(1, "rb\n", 3);
		else
			write(1, "Error in moves.c:rotate\n", 24);
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
		else if ((*head)->name == 'B')
			write(1, "rrb\n", 4);
		else
			write(1, "Error in moves.c:reverse_rotate\n", 32);
	}
}
void	push(t_pslist **src, t_pslist **dest)
{
	t_pslist	*src_fst;
	t_pslist	*src_sec;
	char		stack_name;

	if (!src || !dest || !(*src))
		return ;
	if ((*dest)->name == 'C')
	{
		free(*dest);
		*dest = NULL;
		stack_name = 'B';
	}
	else
		stack_name = (*dest)->name;
	src_fst = *src;
	src_sec = src_fst->next;
	*src = src_sec;
	src_fst->next = *dest;
	*dest = src_fst;
	src_fst->name = stack_name;
	if (src_fst->name == 'A')
		write(1, "pa\n", 3);
	else if (src_fst->name == 'B')
		write(1, "pb\n", 3);
	else
		write(1, "Error in moves.c:push\n", 22);
}
