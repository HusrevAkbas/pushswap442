/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:26:54 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/02 14:11:13 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(t_pslist *head)
{
	while (head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
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
			return clear_list(list);
		new->name = 'A';
		next->next = new;
		next = new;
		i++;
	}
	return (list);
}
