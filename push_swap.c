/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:26:52 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/07 15:42:55 by huakbas          ###   ########.fr       */
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
	else if (is_swap_a(*stack_a) && is_swap_b(*stack_b))
		swap_both(stack_a, stack_b);
	else
		push(stack_a, stack_b);
}
void	magic_two(t_pslist **stack_a, t_pslist **stack_b)
{
	t_pslist	*greatest;

	if (is_swap_a(*stack_a))
	{
		if (is_swap_b(*stack_b))
			swap_both(stack_a, stack_b);
		else
			swap(stack_a, 1);
	}
	greatest = find_greatest(*stack_b);
	if (greatest->second_greatest == *stack_b
		&& greatest->data < (*stack_a)->data)
		push(stack_b, stack_a);
	if (greatest == *stack_b)
		push(stack_b, stack_a);
	else if (greatest->index <= size_list(*stack_b) / 2)
		rotate(stack_b, 1);
	else
		reverse_rotate(stack_b, 1);
}
void	start_magic(char **args)
{
	t_pslist	*stack_a;
	t_pslist	*stack_b;

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
	{
		magic_one(&stack_a, &stack_b);
	//print_list(stack_a);
	//print_list(stack_b);
	}
	while ( size_list(stack_b) > 2)
	{
		magic_two(&stack_a, &stack_b);
	//print_list(stack_a);
	//print_list(stack_b);
	}
	if (stack_b->name != 'C')
	{
		if (is_swap_a(stack_a))
			swap(&stack_a, 1);
		if (is_swap_b(stack_b))
			swap(&stack_b, 1);
		push(&stack_b, &stack_a);
		push(&stack_b, &stack_a);
	}
	print_list(stack_a);
	print_list(stack_b);
	printf("size %i\n", size_list(stack_a));
	t_pslist *node;
	node = stack_a;
	while (node->next)
	{
		if (node->data > node->next->data)
		{
			printf("NOT ORDERED");
			return ;
		}
		node = node->next;
	}
	printf("IN ORDER");
	//WRITE CODES ABOVE THIS
	clear_list(stack_b);
	clear_list(stack_a);
}
int	main(int argc, char **argv)
{
	char	**nums;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		if (!is_args_num(nums)) //check if all args are numbers
		{
			clear_split(nums);
			return print_error();
		}
		start_magic(nums);
		clear_split(nums);
		return (0);
	}
	if (!is_args_num(&argv[1])) //check if all args are numbers
		return print_error();
	start_magic(&argv[1]);
	return (0);
}
