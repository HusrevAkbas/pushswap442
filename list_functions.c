#include "push_swap.h"

t_ilist	*new_list(int num)
{
	t_ilist	*list;
	
	list = malloc(sizeof(t_ilist));
	list->data = num;
	list->count = 1;
	list->average = num;
	list->max = num;
	list->min = num;
	list->next = NULL;
	list->medium = num;
}

void	add_list(t_ilist *begin, t_ilist *toadd)
{
	while (begin->next)
		begin = begin->next;
	begin->next = toadd;
}
