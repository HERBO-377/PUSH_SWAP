/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:23:16 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/11 17:45:11 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

make -C ../libs/libft

cc -Wall -Wextra -Werror \
test_sort_small.c \
../src/sort/sort_2.c \
../src/sort/sort_3.c \
../src/sort/sort_5.c \
../src/operations/swap.c \
../src/operations/push.c \
../src/operations/rotate.c \
../src/operations/reverse_rotate.c \
../src/stack/node_new.c \
../src/stack/node_addback.c \
../src/stack/node_addfront.c \
../src/stack/node_last.c \
../src/stack/node_clear.c \
../src/analysis/index.c \
../src/analysis/index_utils.c \
../src/dispatch/check_order.c \
-I../include -I../libs/libft \
-L../libs/libft -lft \
-o test_sort

*/

#include "push_swap.h"
#include "ft_printf.h"

static void	print_stack(char *name, t_node *stack)
{
	ft_printf("%s: ", name);
	while (stack)
	{
		ft_printf("%d(index:%d) ", stack->content, stack->index);
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

static void	test_sort_2(void)
{
	t_node	*a;
	int		nums[2];

	a = NULL;
	nums[0] = 2;
	nums[1] = 1;
	add_nums(&a, nums, 2);
	ft_printf("\n--- TEST SORT_2 ---\n");
	print_stack("Antes", a);
	sort_2(&a);
	print_stack("Después", a);
	node_clear(&a);
}

static void	test_sort_3_case(int n1, int n2, int n3)
{
	t_node	*a;
	int		nums[3];

	a = NULL;
	nums[0] = n1;
	nums[1] = n2;
	nums[2] = n3;
	add_nums(&a, nums, 3);
	ft_printf("\n--- TEST SORT_3: %d %d %d ---\n", n1, n2, n3);
	print_stack("Antes", a);
	sort_3(&a);
	print_stack("Después", a);
	node_clear(&a);
}

static void	test_sort_5_case(int n1, int n2, int n3, int n4, int n5)
{
	t_node	*a;
	t_node	*b;
	int		nums[5];

	a = NULL;
	b = NULL;
	nums[0] = n1;
	nums[1] = n2;
	nums[2] = n3;
	nums[3] = n4;
	nums[4] = n5;
	add_nums(&a, nums, 5);
	index_stack(a);
	ft_printf("\n--- TEST SORT_5: %d %d %d %d %d ---\n", n1, n2, n3, n4, n5);
	print_stack("Antes A", a);
	sort_5(&a, &b);
	print_stack("Después A", a);
	print_stack("Después B", b);
	node_clear(&a);
	node_clear(&b);
}

int	main(void)
{
	test_sort_2();
	test_sort_3_case(1, 2, 3);
	test_sort_3_case(1, 3, 2);
	test_sort_3_case(2, 1, 3);
	test_sort_3_case(2, 3, 1);
	test_sort_3_case(3, 1, 2);
	test_sort_3_case(3, 2, 1);
	test_sort_5_case(5, 4, 3, 2, 1);
	test_sort_5_case(4, 2, 5, 1, 3);
	test_sort_5_case(2, 1, 3, 5, 4);
	return (0);
}
