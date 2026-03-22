/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 11:32:47 by asadik            #+#    #+#             */
/*   Updated: 2026/03/22 12:23:05 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

/// Swap first two elements.
void	swap(t_list *stack, char *str)
{
	void	*tmp;

	if (stack && stack->next)
	{
		tmp = stack->next->content;
		stack->next->content = stack->content;
		stack->content = tmp;
	}
	ft_printf("%s\n", str);
}

/// Push first element of origin to start of target.
void	push(t_list **origin, t_list **target, char *str)
{
	t_list	*new_head;

	if (*origin)
	{
		new_head = (*origin)->next;
		ft_lstadd_front(target, *origin);
		*origin = new_head;
	}
	ft_printf("%s\n", str);
}

/// First element becomes last.
void	rotate(t_list **stack, char *str)
{
	t_list	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
		ft_lstadd_back(stack, tmp);
	}
	ft_printf("%s\n", str);
}

/// Last element becomes first.
void	reverse_rotate(t_list **stack, char *str)
{
	t_list	*last;
	t_list	*second_last;

	if (*stack && (*stack)->next)
	{
		second_last = *stack;
		while (second_last->next->next)
			second_last = second_last->next;
		last = second_last->next;
		second_last->next = NULL;
		ft_lstadd_front(stack, last);
	}
	ft_printf("%s\n", str);
}
