/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:26:46 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/05 14:03:59 by huakbas          ###   ########.fr       */
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
	char			name;
	int				greaters;
	int				smallers;
	int				index;
	struct s_pslist	*second_greatest;
	struct s_pslist	*last;
	struct s_pslist	*next;
} t_pslist;

void	print_list(t_pslist *head); // FOR TEST - CAN BE DELETED
t_pslist	*new_list(int num);
void	add_back(t_pslist *begin, t_pslist *toadd);
int	is_ordered(t_pslist *head);
int	is_rotate_a(t_pslist *head);
int	is_rotate_b(t_pslist *head);
int	is_swap_a(t_pslist *head);
int	is_swap_b(t_pslist *head);
t_pslist	*find_greatest(t_pslist *head);
t_pslist	*set_list(char **args);
t_pslist	*set_list_B(char *arg);
void	swap(t_pslist **head, int print_msg);
void	rotate(t_pslist **head, int print_msg);
void	reverse_rotate(t_pslist **head, int print_msg);
void	push(t_pslist **src, t_pslist **dest);
t_pslist	*push_first(t_pslist **src);
t_pslist	*clear_list(t_pslist *head);
int	is_args_num(char **args);
int	print_error();
int	size_list(t_pslist *head);
void	swap_both(t_pslist **list_a, t_pslist **list_b);
void	rotate_both(t_pslist **list_a, t_pslist **list_b);
void	reverse_rotate_both(t_pslist **list_a, t_pslist **list_b);

#endif // PUSH_SWAP_H