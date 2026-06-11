#ifndef PARSE_STRUCT_H
# define PARSE_STRUCT_H

# include "node_struct.h"
# include "flag_struct.h"

typedef struct	s_parse
{
	t_node	*stack;
	t_flags	flag;
}	t_parse;

#endif
