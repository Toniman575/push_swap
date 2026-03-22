/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 12:29:30 by asadik            #+#    #+#             */
/*   Updated: 2026/03/22 12:33:57 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "operations.h"
#include "sort_utils.h"

static void	sort_3(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)(*stack)->content;
	b = *(int *)(*stack)->next->content;
	c = *(int *)(*stack)->next->next->content;
	if (a > b && a > c)
		rotate(stack, "ra");
	else if (b > a && b > c)
		reverse_rotate(stack, "rra");
	a = *(int *)(*stack)->content;
	b = *(int *)(*stack)->next->content;
	if (a > b)
		swap(*stack, "sa");
}

static void	sort_4_5(t_list **stack_a, t_list **stack_b, int size,
	int current_min)
{
	int	pos;

	pos = get_min_pos(*stack_a, current_min);
	if (pos <= size / 2)
		while (pos-- > 0)
			rotate(stack_a, "ra");
	else
		while (pos++ < size)
			reverse_rotate(stack_a, "rra");
	push(stack_a, stack_b, "pb");
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	current_min;

	size = ft_lstsize(*stack_a);
	current_min = 0;
	if (size == 2 && *(int *)(*stack_a)->content >
		*(int *)(*stack_a)->next->content)
		swap(*stack_a, "sa");
	else
	{
		while (size > 3)
		{
			sort_4_5(stack_a, stack_b, size, current_min);
			size--;
			current_min++;
		}
		sort_3(stack_a);
		while (*stack_b)
			push(stack_b, stack_a, "pa");
	}
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		max_bits;
	int		i;
	int		j;

	init_radix(&size, stack_a, &max_bits, &i);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (*stack_a)
				rotate_or_push(stack_a, stack_b, i, j);
			else
				break ;
		}
		while (*stack_b)
			push(stack_b, stack_a, "pa");
		i++;
	}
}
