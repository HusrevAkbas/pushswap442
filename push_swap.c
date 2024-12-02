/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:26:52 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/02 19:47:24 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	magic_one(t_pslist **stack_a, t_pslist **stack_b)
{
	if (is_rotate_a(*stack_a))
	{
		if (is_rotate_b(*stack_b))
			rotate_both(stack_a, stack_b);
		else
			rotate(stack_a, 1);
	}
	else if (is_rotate_b(*stack_b))
		rotate(stack_b, 1);
	else if (is_swap_a(*stack_a))
	{
		if (is_swap_b(*stack_b))
			swap_both(stack_a, stack_b);
		swap(stack_a, 1);
	}
	else if (is_swap_b(*stack_b))
		swap(stack_b, 1);
	else
		push(stack_a, stack_b);
}
void	magic_two(t_pslist **stack_a, t_pslist **stack_b)
{
	t_pslist	*greatest;

	greatest = find_greatest(*stack_b);
	if (is_swap_a(*stack_a))
	{
		if (is_swap_a(*stack_b))
			swap_both(stack_a, stack_b);
		else
			swap(stack_a, 1);
	}
	if (greatest->index <= greatest->size)
	{
		greatest = find_greatest(*stack_b);
		if (greatest->second_greatest == *stack_b)
			push(stack_b, stack_a);
		greatest = find_greatest(*stack_b);
		if (greatest == *stack_b)
			push(stack_b, stack_a);
		reverse_rotate(stack_b, 1);
	}
	if (greatest->index > greatest->size / 2)
	{
		greatest = find_greatest(*stack_b);
		if (greatest->second_greatest == *stack_b)
			push(stack_b, stack_a);
		greatest = find_greatest(*stack_b);
		if (greatest->index == 0)
			push(stack_b, stack_a);
		rotate(stack_b, 1);
	}
}
void	start_magic(char **args)
{
	t_pslist	*stack_a;
	t_pslist	*stack_b;
	int			size;

	stack_b = set_list_B(args[0]);
	if (!stack_b)
		return ;
	stack_b->name = 'C';
	stack_a = set_list(args);
	if (!stack_a)
	{
		clear_list(stack_b);
		return ;
	}
	if (is_ordered(stack_a))
	{
		clear_list(stack_a);
		printf("Numbers are ordered!\n");
		return ;
	}
	print_list(stack_a);
	while (!is_ordered(stack_a))
		magic_one(&stack_a, &stack_b);
	size = size_list(stack_b);
	while (size > 2)
	{
		magic_two(&stack_a, &stack_b);
		size = size_list(stack_b);
	}
	if (!is_swap_a(stack_b))
		swap(&stack_b, 1);
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	print_list(stack_a);
	print_list(stack_b);
	//WRITE CODES ABOVE THIS
	clear_list(stack_b);
	clear_list(stack_a);
}
int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!is_args_num(&argv[1])) //check if all args are numbers
		return print_error();
	start_magic(&argv[1]);
	return (0);
}
