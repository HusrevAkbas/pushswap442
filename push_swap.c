/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:26:52 by huakbas           #+#    #+#             */
/*   Updated: 2024/11/30 18:17:37 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	start_magic(char **args)
{
	t_spec		*spec;
	t_pslist	*list;
	t_pslist	*head;

	list = set_list(args);
	spec = set_spec(list);
	head = list;
	if (spec->is_ordered)
	{
		clear_list(head);
		free(spec);
		printf("Numbers are ordered!\n");
		return ;
	}
	print_list(head);
	reverse_rotate(&head);
	print_list(head);
	swap(&head);
	print_list(head);
	rotate(&head);
	print_list(head);
	swap(&head);
	print_list(head);
	reverse_rotate(&head);
	print_list(head);
	clear_list(head);
	free(spec);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if(!is_args_num(&argv[1])) //check if all args are numbers
	{
		print_error();
		return (127);
	}
	start_magic(&argv[1]);
	printf("work!\n");
	return (0);
}
