/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:29:38 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/11 12:36:53 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		clear_split(nums);
		return (0);
	}
	if (!is_args_num(&argv[1]))
		return (print_error());
	return (0);
}
