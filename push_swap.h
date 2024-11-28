/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:26:46 by huakbas           #+#    #+#             */
/*   Updated: 2024/11/28 13:44:55 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h> //DELETE THIS LINE

typedef struct s_ilist
{
	int				data;
	int				medium;
	int				average;
	int				max;
	int				min;
	int				count;
	struct s_ilist	*next;
} t_ilist;

int	ft_isdigit(int c);
t_ilist	*new_list(int num);
void	add_list(t_ilist *begin, t_ilist *toadd);

#endif // PUSH_SWAP_H