/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:26:52 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/01 18:55:18 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_magic(char **args)
{
	t_spec		*spec;
	t_pslist	*stack_a;
	t_pslist	*stack_b;

	stack_b = NULL;
	stack_a = set_list(args);
	if (!stack_a)
		return ;
	spec = set_spec(stack_a);
	if (!spec)
	{
		//clear_list(stack_a);
		return ;
	}
	if (spec->is_ordered)
	{
		clear_list(stack_a);
		free(spec);
		printf("Numbers are ordered!\n");
		return ;
	}
	print_list(stack_a);
	stack_b = push_first(&stack_a);
	push(&stack_a, &stack_b);
	print_list(stack_a);
	print_list(stack_b);
	swap(&stack_a, 1);
	print_list(stack_a);
	swap(&stack_b, 1);
	print_list(stack_b);
	rotate(&stack_a, 1);
	print_list(stack_a);
	rotate(&stack_b, 1);
	print_list(stack_b);
	push(&stack_a, &stack_b);
	print_list(stack_a);
	print_list(stack_b);
	reverse_rotate(&stack_a, 1);
	print_list(stack_a);
	reverse_rotate(&stack_b, 1);
	print_list(stack_b);
	swap_both(&stack_a, &stack_b);
	print_list(stack_a);
	print_list(stack_b);
	rotate_both(&stack_a, &stack_b);
	print_list(stack_a);
	print_list(stack_b);
	reverse_rotate_both(&stack_a, &stack_b);
	print_list(stack_a);
	print_list(stack_b);
	
	//WRITE TEST ABOVE THIS
	clear_list(stack_a);
	clear_list(stack_b);
	free(spec);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!is_args_num(&argv[1])) //check if all args are numbers
		return print_error();
	start_magic(&argv[1]);
	printf("work!\n");
	return (0);
}
