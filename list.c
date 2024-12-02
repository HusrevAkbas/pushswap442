/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:27:05 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/02 14:12:26 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pslist	*new_list(int num)
{
	t_pslist	*list;
	
	list = malloc(sizeof(t_pslist));
	if (!list)
		return (NULL);
	list->data = num;
	list->next = NULL;
	return (list);
}
void	add_back(t_pslist *head, t_pslist *toadd)
{
	if (!head)
		return ;
	while (head->next)
		head = head->next;
	head->next = toadd;
}

void	add_front(t_pslist **head, t_pslist *toadd)
{
	if (!head || !toadd)
		return ;
	toadd->next = *head;
	*head = toadd;
}

t_pslist	*clear_list(t_pslist *head)
{
	if (!head)
		return (NULL);
	if (head->next)
		clear_list(head->next);
	free(head);
	head = NULL;
	return (NULL);
}