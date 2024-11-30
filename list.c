/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:27:05 by huakbas           #+#    #+#             */
/*   Updated: 2024/11/30 17:19:09 by huakbas          ###   ########.fr       */
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
t_pslist	*find_last(t_pslist *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

void	add_back(t_pslist *head, t_pslist *toadd)
{
	while (head->next)
		head = head->next;
	head->next = toadd;
}

void	add_front(t_pslist **head, t_pslist *toadd)
{
	toadd->next = *head;
	*head = toadd;
}

void	clear_list(t_pslist *head)
{
	if (!head)
		return ;
	if (head->next)
		clear_list(head->next);
	free(head);
	head = NULL;
}