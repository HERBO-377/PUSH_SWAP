#include "push_swap.h"

void	node_addback(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->prev = NULL;
		return ;
	}
	last = node_last(*lst);
	last->next = new;
	new->prev = last;
}
