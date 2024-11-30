/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:03:53 by huakbas           #+#    #+#             */
/*   Updated: 2024/11/30 21:02:51 by huakbas          ###   ########.fr       */
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
	unsigned int	cmp;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (j == 0 && (args[i][j] == '-' || args[i][j] == '+'))
				j++;
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		cmp = 1;
		while ((int) cmp < i)
		{
			if (ft_strncmp(args[i], args[cmp], j) == 0)
				return (0);
			cmp++;
		}
		i++;
	}
	return (1);
}

void	print_list(t_pslist *head) // FOR TEST - CAN BE DELETED
{
	if (!head)
	{
		printf("no more elements\n");
		return ;
	}
	printf("stack: %c ", head->name);
	while (head->next)
	{
		printf("%i	", head->data);
		head = head->next;
	}
	printf("%i\n", head->data);
	//printf("\n");
}