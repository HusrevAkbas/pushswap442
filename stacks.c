/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:26:54 by huakbas           #+#    #+#             */
/*   Updated: 2024/11/29 16:59:49 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_spec	*new_spec()
{
	t_spec		*spec;

	spec = malloc(sizeof(t_spec));
	if (!spec)
		return (NULL);
	spec->average = 0;
	spec->count = 0;
	spec->is_ordered = 1;
	spec->max = INT_MIN;
	spec->medium = 0;
	spec->min = INT_MAX;
	spec->sum = 0;
	return (spec);
}
t_spec	*set_spec(t_pslist *list)
{
	t_spec	*spec;

	spec = new_spec();
	while (list)
	{
		spec->count += 1;
		spec->sum += list->data;
		spec->average = spec->sum / spec->count;
		if (spec->max < list->data)
			spec->max = list->data;
		if (spec->min > list->data)
			spec->min = list->data;
		if (list->data < spec->max)
			spec->is_ordered = 0;
		list = list->next;
	}
	return (spec);
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
	next = list;
	i = 1;
	while (args[i])
	{
		new = new_list(ft_atoi(args[i]));
		next->next = new;
		next = new;
		i++;
	}
	return (list);
}