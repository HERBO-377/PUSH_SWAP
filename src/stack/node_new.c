#include "push_swap.h"

t_node	*node_new(int content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->index = -1;
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
