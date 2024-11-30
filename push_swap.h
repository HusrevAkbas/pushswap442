/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:26:46 by huakbas           #+#    #+#             */
/*   Updated: 2024/11/30 17:15:02 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include <stdio.h> //DELETE THIS LINE

typedef struct s_pslist
{
	int				data;
	struct s_pslist	*next;
} t_pslist;

typedef struct s_spec
{
	int				medium;
	int				average;
	int				min;
	int				max;
	int				count;
	int				is_ordered;
	long			sum;
	int				count_1_10;
	int				count_1_5;
	int				count_1_3;
	int				size_stack_A;
	int				size_stack_B;
} t_spec;

t_pslist	*new_list(int num);
void	add_back(t_pslist *begin, t_pslist *toadd);
t_spec	*new_spec();
t_spec	*set_spec(t_pslist *list);
t_pslist	*set_list(char **args);
void	swap(t_pslist **head);
void	rotate(t_pslist **head);
void	reverse_rotate(t_pslist **head);
void	push(t_pslist **src, t_pslist **dest);
void	clear_list(t_pslist *head);

#endif // PUSH_SWAP_H