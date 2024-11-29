/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:26:46 by huakbas           #+#    #+#             */
/*   Updated: 2024/11/29 11:39:19 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //DELETE THIS LINE

typedef struct s_pslist
{
	int				data;
	struct s_spec	*spec;
	struct s_pslist	*next;
} t_pslist;

typedef struct s_spec
{
	int	medium;
	int	average;
	int	min;
	int	max;
	int	count;
	int	is_ordered;
} t_spec;


int	ft_isdigit(int c);
t_pslist	*new_list(int num, t_spec *spec);
void	add_list(t_pslist *begin, t_pslist *toadd);

#endif // PUSH_SWAP_H