/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:26:52 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/15 12:47:51 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	magic_three(t_pslist **stack_a)
{
	t_pslist	*node;
	t_pslist	*small;

	while (!is_ordered(*stack_a))
	{
		node = *stack_a;
		small = *stack_a;
		while (node->next)
		{
			node = node->next;
			if (node->data < small->data)
				small = node;
		}
		if (find_greatest(*stack_a) == *stack_a)
			rotate(stack_a, 1);
		else if (small == node)
			reverse_rotate(stack_a, 1);
		else
			swap(stack_a, 1);
	}
}

void	magic_one(t_pslist **stack_a, t_pslist **stack_b)
{
	t_pslist	*node;
	t_pslist	*small;

	node = *stack_a;
	small = node;
	while (node->next)
	{
		if (node->next->data < small->data)
			small = node->next;
		node = node->next;
	}
	if (size_list(*stack_a) > 3 && node == small)
		reverse_rotate(stack_a, 1);
	else if (is_rotate_a(*stack_a))
	{
		if (is_rotate_b(*stack_b))
			rotate_both(stack_a, stack_b, 1);
		else
			rotate(stack_a, 1);
	}
	else if (is_rotate_b(*stack_b))
		rotate(stack_b, 1);
	else
		push(stack_a, stack_b, 1);
}

void	magic_two(t_pslist **stack_a, t_pslist **stack_b)
{
	t_pslist	*greatest;

	greatest = find_greatest(*stack_b);
	find_greaters(*stack_b);
	if ((*stack_b)->greaters <= (*stack_a)->count)
	{
		if ((*stack_a)->data < (*stack_b)->data)
			rotate(stack_a, 1);
		else if ((*stack_a)->last != find_greatest(*stack_a)
			&& (*stack_a)->last->data > (*stack_b)->data)
			reverse_rotate(stack_a, 1);
		else
			push(stack_b, stack_a, 1);
	}
	else
	{
		if (greatest->index <= size_list(*stack_b) / 2)
			rotate(stack_b, 1);
		else if ((*stack_a)->last != find_greatest(*stack_a)
			&& (*stack_a)->last->data > greatest->data)
			reverse_rotate_both(stack_a, stack_b, 1);
		else
			reverse_rotate(stack_b, 1);
	}
}

void	start_magic(char **args)
{
	t_pslist	*stack_a;
	t_pslist	*stack_b;

	stack_b = set_list_b(args[0]);
	if (!stack_b)
		return ;
	stack_a = set_list(args);
	if (!stack_a)
	{
		clear_list(stack_b, NULL);
		return ;
	}
	if (size_list(stack_a) == 3)
		magic_three(&stack_a);
	if (!is_ordered(stack_a))
	{
		while (!is_ordered(stack_a))
			magic_one(&stack_a, &stack_b);
		while (size_list(stack_b) >= 1)
			magic_two(&stack_a, &stack_b);
		while (!is_ordered(stack_a))
			reverse_rotate(&stack_a, 1);
	}
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
