/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:00:05 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/01 18:39:53 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_pslist **list_a, t_pslist **list_b)
{
	swap(list_a, 0);
	swap(list_b, 0);
	write(1, "ss\n", 3);
}
void	rotate_both(t_pslist **list_a, t_pslist **list_b)
{
	rotate(list_a, 0);
	rotate(list_b, 0);
	write(1, "rr\n", 3);
}
void	reverse_rotate_both(t_pslist **list_a, t_pslist **list_b)
{
	reverse_rotate(list_a, 0);
	reverse_rotate(list_b, 0);
	write(1, "rrr\n", 4);
}