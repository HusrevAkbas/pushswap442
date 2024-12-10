/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:03:53 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/10 19:43:38 by huakbas          ###   ########.fr       */
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

long	ft_atol(const char *str)
{
	long	a;
	long	b;
	long	is_n;

	if (!str)
		return (0);
	a = 0;
	is_n = -1;
	while (*str == ' ' || (*str <= 13 && *str >= 9))
		str++;
	if (!ft_isdigit(str[0]) && !ft_isdigit(str[1]))
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_n *= -1;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		b = *str - 48;
		a = a * 10 - b;
		str++;
	}
	return (is_n * a);
}

int	is_args_num(char **args)
{
	int		i;

	if (!args || !args[0])
		return (0);
	i = 0;
	while (args[i])
	{
		if (!is_number(args[i]) || is_duplicate(args, i))
			return (0);
		if (ft_atol(args[i]) > INT_MAX || ft_atol(args[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}
