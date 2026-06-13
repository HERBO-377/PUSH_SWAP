/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:17:01 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/11 17:44:19 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Compile:

make -C ../libs/libft

cc -Wall -Wextra -Werror \
test_operations.c \
../src/operations/swap.c \
../src/operations/push.c \
../src/operations/rotate.c \
../src/operations/reverse_rotate.c \
../src/stack/node_new.c \
../src/stack/node_addback.c \
../src/stack/node_addfront.c \
../src/stack/node_last.c \
../src/stack/node_clear.c \
-I../include -I../libs/libft \
-L../libs/libft -lft \
-o test_operations

*/

#include "push_swap.h"
#include "ft_printf.h"

static void	print_stack(char *name, t_node *stack)
{
	ft_printf("%s: ", name);
	while (stack)
	{
		ft_printf("%d ", stack->content);
		stack = stack->next;
	}
	ft_printf("\n");
}

static void	add_nums(t_node **stack, int *nums, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		node_addback(stack, node_new(nums[i]));
		i++;
	}
}

static void	test_swap(void)
{
	t_node	*a;
	t_node	*b;
	int		nums_a[3];
	int		nums_b[2];

	a = NULL;
	b = NULL;
	nums_a[0] = 2;
	nums_a[1] = 1;
	nums_a[2] = 3;
	nums_b[0] = 5;
	nums_b[1] = 4;
	add_nums(&a, nums_a, 3);
	add_nums(&b, nums_b, 2);
	ft_printf("\n--- TEST SWAP ---\n");
	print_stack("A antes", a);
	print_stack("B antes", b);
	sa(&a);
	sb(&b);
	ss(&a, &b);
	print_stack("A después", a);
	print_stack("B después", b);
	node_clear(&a);
	node_clear(&b);
}

static void	test_push(void)
{
	t_node	*a;
	t_node	*b;
	int		nums_a[3];
	int		nums_b[2];

	a = NULL;
	b = NULL;
	nums_a[0] = 1;
	nums_a[1] = 2;
	nums_a[2] = 3;
	nums_b[0] = 4;
	nums_b[1] = 5;
	add_nums(&a, nums_a, 3);
	add_nums(&b, nums_b, 2);
	ft_printf("\n--- TEST PUSH ---\n");
	print_stack("A antes", a);
	print_stack("B antes", b);
	pb(&a, &b);
	pa(&a, &b);
	print_stack("A después", a);
	print_stack("B después", b);
	node_clear(&a);
	node_clear(&b);
}

static void	test_rotate(void)
{
	t_node	*a;
	t_node	*b;
	int		nums_a[3];
	int		nums_b[3];

	a = NULL;
	b = NULL;
	nums_a[0] = 1;
	nums_a[1] = 2;
	nums_a[2] = 3;
	nums_b[0] = 4;
	nums_b[1] = 5;
	nums_b[2] = 6;
	add_nums(&a, nums_a, 3);
	add_nums(&b, nums_b, 3);
	ft_printf("\n--- TEST ROTATE ---\n");
	print_stack("A antes", a);
	print_stack("B antes", b);
	ra(&a);
	rb(&b);
	rr(&a, &b);
	print_stack("A después", a);
	print_stack("B después", b);
	node_clear(&a);
	node_clear(&b);
}

static void	test_reverse_rotate(void)
{
	t_node	*a;
	t_node	*b;
	int		nums_a[3];
	int		nums_b[3];

	a = NULL;
	b = NULL;
	nums_a[0] = 1;
	nums_a[1] = 2;
	nums_a[2] = 3;
	nums_b[0] = 4;
	nums_b[1] = 5;
	nums_b[2] = 6;
	add_nums(&a, nums_a, 3);
	add_nums(&b, nums_b, 3);
	ft_printf("\n--- TEST REVERSE ROTATE ---\n");
	print_stack("A antes", a);
	print_stack("B antes", b);
	rra(&a);
	rrb(&b);
	rrr(&a, &b);
	print_stack("A después", a);
	print_stack("B después", b);
	node_clear(&a);
	node_clear(&b);
}

int	main(void)
{
	test_swap();
	test_push();
	test_rotate();
	test_reverse_rotate();
	return (0);
}
