/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:26:52 by huakbas           #+#    #+#             */
/*   Updated: 2024/11/26 13:27:20 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error()
{
	return (write(1, "Error\n", 6));
}

int	is_args_num(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (j == 0 && (args[i][j] != '-' || args[i][j] != '+'))
				j++;
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if(!is_args_num(argv))
		return (print_error());
	//{
	//	j = 0;
	//	while (argv[i][j])
	//	{
	//		if (j == 0 && (argv[i][j] != '-' || argv[i][j] != '+'))
	//			j++;
	//		if (!ft_isdigit(argv[i][j]))
	//			return (0);
	//		j++;
	//	}
	//	i++;
	//}
	printf("work!");
	return (0);
}
