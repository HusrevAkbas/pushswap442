/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:26:46 by huakbas           #+#    #+#             */
/*   Updated: 2024/11/29 17:12:47 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
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
} t_spec;


int	ft_isdigit(int c);
int	ft_strncmp(char *s1, char *s2, unsigned int n);
t_pslist	*new_list(int num);
void	add_back(t_pslist *begin, t_pslist *toadd);
t_spec	*new_spec();
t_spec	*set_spec(t_pslist *list);
int	ft_atoi(const char *str);
t_pslist	*set_list(char **args);

#endif // PUSH_SWAP_H