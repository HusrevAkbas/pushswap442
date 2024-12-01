/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:03:53 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/01 19:17:56 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error()
{
	return (write(1, "Error\n", 6));
}
int	is_number(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (i == 0 && (arg[i] == '-' || arg[i] == '+'))
			i++;
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}
int	is_duplicate(char **args, int i)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(args[j]);
	if (ft_strlen(args[i]) > ft_strlen(args[j]))
		len = ft_strlen(args[i]);
	while (j < i)
	{
		if (!ft_strncmp(args[i], args[j], len))
			return (1);
		j++;
	}
	return (0);
}

int	is_args_num(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!is_number(args[i]))
			return (0);
		if (is_duplicate(args, i))
			return (0);
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
	printf("stack: %c	", head->name);
	while (head->next)
	{
		printf("%i	", head->data);
		head = head->next;
	}
	printf("%i\n", head->data);
	//printf("\n");
}