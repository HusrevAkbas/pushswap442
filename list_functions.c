/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:27:05 by huakbas           #+#    #+#             */
/*   Updated: 2024/11/29 15:54:08 by huakbas          ###   ########.fr       */
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
	while (head->next)
		head = head->next;
	head->next = toadd;
}

t_pslist	*add_front(t_pslist *head, t_pslist *toadd)
{
	toadd->next = head;
	return (toadd);
}