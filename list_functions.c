#include "push_swap.h"

t_pslist	*new_list(int num, t_spec *spec)
{
	t_pslist	*list;
	
	list = malloc(sizeof(t_pslist));
	list->data = num;
	list->spec = spec;
	list->next = NULL;
	return (list);
}

void	add_list(t_pslist *begin, t_pslist *toadd)
{
	while (begin->next)
		begin = begin->next;
	begin->next = toadd;
}
