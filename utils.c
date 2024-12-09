/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:03:53 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/09 14:40:07 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(void)
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
	len = ft_strlen(args[i]);
	while (j < i)
	{
		if (ft_strlen(args[j]) > ft_strlen(args[i]))
			len = ft_strlen(args[j]);
		if (!ft_strncmp(args[i], args[j], len))
			return (1);
		j++;
	}
	return (0);
}

int	is_args_num(char **args)
{
	int	i;

	if (!args || !args[0])
		return (0);
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

void	print_list(t_pslist *head)
{
	ft_printf("%3c :", head->name);
	while (head)
	{
		ft_printf("%3i |", head->data);
		head = head->next;
	}
	ft_printf("\n");
}