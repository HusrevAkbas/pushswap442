/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:26:52 by huakbas           #+#    #+#             */
/*   Updated: 2024/11/30 17:27:50 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error()
{
	return (write(1, "Error\n", 6));
}

int	is_args_num(char **args)
{
	int	i;
	int	j;
	unsigned int	cmp;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (j == 0 && (args[i][j] == '-' || args[i][j] == '+'))
				j++;
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		cmp = 1;
		while ((int) cmp < i)
		{
			if (ft_strncmp(args[i], args[cmp], j) == 0)
				return (0);
			cmp++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_spec		*spec;
	t_pslist	*list;
	t_pslist	*head;

	if (argc < 2)
		return (0);
	if(!is_args_num(argv)) //check if all args are numbers
	{
		print_error();
		return (127);
	}
	list = set_list(&argv[1]);
	spec = set_spec(list);
	head = list;
	if (spec->is_ordered)
	{
		clear_list(head);
		free(spec);
		return (printf("Numbers are ordered!\n"));
	}
	while (list)
	{
		printf("num %i\n", list->data);
		list = list->next;
	}
	reverse_rotate(&head);
	swap(&head);
	rotate(&head);
	swap(&head);
	reverse_rotate(&head);
printf("count:%i  avg:%i  order:%i max:%i med:%i min:%i sum:%li\n", 
spec->count, spec->average, spec->is_ordered, spec->max, 
spec->medium, spec->min, spec->sum);
	list = head;
	while (list)
	{
		printf("num %i\n", list->data);
		list = list->next;
	}
	clear_list(head);
	free(spec);
	printf("work!\n");
	return (0);
}
