/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_complex_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:02:15 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/11 17:46:34 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

make -C ../libs/libft

cc -Wall -Wextra -Werror \
test_complex_sort.c \
../src/sort/complex_sort.c \
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
-o test_complex

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

static void	test_complex_case(int *nums, int size)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	add_nums(&a, nums, size);
	index_stack(a);
	ft_printf("\n--- TEST COMPLEX_SORT ---\n");
	print_stack("Antes A", a);
	complex_sort(&a, &b);
	print_stack("Después A", a);
	print_stack("Después B", b);
	if (check_order(a) && !b)
		ft_printf("RESULT: OK\n");
	else
		ft_printf("RESULT: KO\n");
	node_clear(&a);
	node_clear(&b);
}

int	main(void)
{
	int	nums1[6] = {4, 2, 6, 1, 3, 5};
	int	nums2[10] = {9, 1, 8, 2, 7, 3, 6, 4, 5, 0};
	int	nums3[15] = {14, 3, 7, 1, 9, 0, 12, 5, 2, 11, 4, 13, 6, 10, 8};

	test_complex_case(nums1, 6);
	test_complex_case(nums2, 10);
	test_complex_case(nums3, 15);
	return (0);
}
