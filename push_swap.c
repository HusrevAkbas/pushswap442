/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:26:52 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/07 17:27:43 by huakbas          ###   ########.fr       */
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

void	last_touch(t_pslist **stack_a, t_pslist **stack_b)
{
	if (is_swap_a(*stack_a))
		swap(stack_a, 1);
	push(stack_b, stack_a);
}

void	start_magic(char **args)
{
	t_pslist	*stack_a;
	t_pslist	*stack_b;

	stack_b = set_list_b(args[0]);
	if (!stack_b)
		return ;
	stack_b->name = 'C';
	stack_a = set_list(args);
	if (!stack_a)
	{
		clear_list(stack_b, NULL);
		return ;
	}
	if (is_ordered(stack_a))
	{
		clear_list(stack_a, stack_b);
		return ;
	}
	while (!is_ordered(stack_a))
		magic_one(&stack_a, &stack_b);
	while (size_list(stack_b) > 1)
		magic_two(&stack_a, &stack_b);
	if (stack_b->name != 'C')
		last_touch(&stack_a, &stack_b);
	clear_list(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	char	**nums;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		if (!nums)
			return (0);
		if (!is_args_num(nums))
		{
			clear_split(nums);
			return (print_error());
		}
		start_magic(nums);
		clear_split(nums);
		return (0);
	}
	if (!is_args_num(&argv[1]))
		return (print_error());
	start_magic(&argv[1]);
	return (0);
}
