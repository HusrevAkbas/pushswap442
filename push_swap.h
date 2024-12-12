/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:26:46 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/12 14:29:59 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_pslist
{
	int				data;
	char			name;
	int				greaters;
	int				smallers;
	int				index;
	int				count;
	struct s_pslist	*second_greatest;
	struct s_pslist	*last;
	struct s_pslist	*next;
}	t_pslist;

void		add_back(t_pslist *begin, t_pslist *toadd);
t_pslist	*clear_list(t_pslist *head, t_pslist *other);
t_pslist	*find_greatest(t_pslist *head);
void		find_greaters(t_pslist *head);
t_pslist	*new_list(int num);
int			is_args_num(char **args);
int			is_ordered(t_pslist *head);
int			is_rotate_a(t_pslist *head);
int			is_rotate_b(t_pslist *head);
int			is_swap_a(t_pslist *head);
int			is_swap_b(t_pslist *head);
int			print_error(void);
void		push(t_pslist **src, t_pslist **dest, int print_msg);
void		reverse_rotate(t_pslist **head, int print_msg);
void		reverse_rotate_both(t_pslist **lst_a, t_pslist **lst_b, int p_msg);
void		rotate(t_pslist **head, int print_msg);
void		rotate_both(t_pslist **list_a, t_pslist **list_b, int print_msg);
void		set_count(t_pslist *head, int i);
t_pslist	*set_list(char **args);
t_pslist	*set_list_b(char *arg);
int			size_list(t_pslist *head);
void		swap(t_pslist **head, int print_msg);
void		swap_both(t_pslist **list_a, t_pslist **list_b, int print_msg);

#endif // PUSH_SWAP_H