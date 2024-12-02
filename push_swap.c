/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:26:52 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/02 14:13:33 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_magic(char **args)
{
	t_pslist	*stack_a;
	t_pslist	*stack_b;

	stack_b = NULL;
	stack_a = set_list(args);
	if (!stack_a)
		return ;
	if (is_ordered(stack_a))
	{
		clear_list(stack_a);
		printf("Numbers are ordered!\n");
		return ;
	}
	print_list(stack_a);
	
	//WRITE CODES ABOVE THIS
	clear_list(stack_a);
	clear_list(stack_b);
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
