/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:00:15 by huakbas           #+#    #+#             */
/*   Updated: 2024/11/30 17:59:51 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pslist **head)
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
}
void	rotate(t_pslist **head)
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
}
void	reverse_rotate(t_pslist **head)
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
}
t_pslist	*push_first(t_pslist **src)
{
	t_pslist	*fst;
	t_pslist	*sec;

	fst = *src;
	sec = fst->next;
	*src = sec;
	fst->next = NULL;
	return (fst);
}

void	push(t_pslist **src, t_pslist **dest)
{
	t_pslist	*src_fst;
	t_pslist	*src_sec;

	if (!src || !dest || !(*src))
		return ;
	src_fst = *src;
	src_sec = src_fst->next;
	*src = src_sec;
	src_fst->next = *dest;
	*dest = src_fst;
}