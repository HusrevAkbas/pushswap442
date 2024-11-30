/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:26:52 by huakbas           #+#    #+#             */
/*   Updated: 2024/11/30 21:05:28 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_magic(char **args)
{
	t_spec		*spec;
	t_pslist	*stack_a;
	t_pslist	*stack_b;
	t_pslist	*head_a;
	t_pslist	*head_b;

	stack_b = NULL;
	head_b = stack_b;
	stack_a = set_list(args);
	spec = set_spec(stack_a);
	head_a = stack_a;
	if (spec->is_ordered)
	{
		clear_list(head_a);
		free(spec);
		printf("Numbers are ordered!\n");
		return ;
	}
	print_list(stack_a);
	stack_b = push_first(&stack_a);
	print_list(stack_b);
	print_list(stack_a);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	stack_a = push_first(&stack_b);
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	print_list(stack_b);
	print_list(stack_a);
	free(spec);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!is_args_num(&argv[1])) //check if all args are numbers
	{
		print_error();
		return (127);
	}
	start_magic(&argv[1]);
	printf("work!\n");
	return (0);
}
