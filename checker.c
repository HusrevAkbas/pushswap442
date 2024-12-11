/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:29:38 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/11 13:35:01 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check(char **args)
{
	t_pslist	*stack_a;
	t_pslist	*stack_b;
	char		*str;

	stack_b = set_list_b(args[0]);
	if (!stack_b)
		return ;
	stack_a = set_list(args);
	if (!stack_a)
	{
		clear_list(stack_b, NULL);
		return ;
	}
	print_list(stack_a);
	str = get_next_line(0);
	while (str)
	{
		//print_list(stack_a);
		//print_list(stack_b);
		if (!ft_strncmp(str, "Error\n", 6))
			return ;
		//ft_printf("get: %s", str);
		if (!ft_strncmp(str, "sa\n", 3))
			swap(&stack_a, 0);
		else if (!ft_strncmp(str, "sb\n", 3))
			swap(&stack_b, 0);
		else if (!ft_strncmp(str, "pa\n", 3))
			push(&stack_b, &stack_a);
		else if (!ft_strncmp(str, "pb\n", 3))
			push(&stack_a, &stack_b);
		else if (!ft_strncmp(str, "ra\n", 3))
			rotate(&stack_a, 0);
		else if (!ft_strncmp(str, "rb\n", 3))
			rotate(&stack_b, 0);
		else if (!ft_strncmp(str, "rra\n", 3))
			reverse_rotate(&stack_a, 0);
		else if (!ft_strncmp(str, "rrb\n", 3))
			reverse_rotate(&stack_b, 0);
		else if (!ft_strncmp(str, "ss\n", 3))
			swap_both(&stack_a, &stack_b);
		else if (!ft_strncmp(str, "rr\n", 3))
			rotate_both(&stack_a, &stack_b);
		else if (!ft_strncmp(str, "rrr\n", 3))
			reverse_rotate_both(&stack_a, &stack_b);
		str = get_next_line(0);
	}
	if (!is_ordered(stack_a) || (size_list(stack_b) != 0 && stack_b->name == 'B'))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main (int argc, char **argv)
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
		check(nums);
		clear_split(nums);
		return (0);
	}
	if (!is_args_num(&argv[1]))
		return (print_error());
	check(&argv[1]);
	return (0);
}
