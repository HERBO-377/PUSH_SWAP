#ifndef NODE_STRUCT_H
# define NODE_STRUCT_H

typedef struct	s_node
{
	int				content;// numero original
        int				index; // numero normalizado
	struct s_node	*next; //sig nodo.
	struct s_node	*prev;
}	t_node;

#endif
