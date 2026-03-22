/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 12:30:33 by asadik            #+#    #+#             */
/*   Updated: 2026/03/22 13:03:44 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "operations.h"

int	get_min_pos(t_list *stack, int val)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (*(int *)stack->content == val)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void	init_radix(int *size, t_list **stack_a, int *max_bits, int *i)
{
	*size = ft_lstsize(*stack_a);
	*max_bits = 0;
	while ((*size - 1) >> *max_bits != 0)
		max_bits++;
	*i = 0;
}

void	rotate_or_push(t_list **stack_a, t_list **stack_b, int i)
{
	if (((*(int *)(*stack_a)->content >> i) & 1) == 1)
		rotate(stack_a, "ra");
	else
		push(stack_a, stack_b, "pb");
}
