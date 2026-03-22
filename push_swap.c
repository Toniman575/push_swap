/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:12:32 by asadik            #+#    #+#             */
/*   Updated: 2026/03/22 13:41:01 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "libft/libft.h"
#include "parse.h"
#include "sort.h"

static bool	is_sorted(t_list *stack_a)
{
	while (stack_a->next)
	{
		if (*(int *)stack_a->content > *(int *)stack_a->next->content)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	int		*numbers;
	int		len;
	t_list	*stack_a;
	t_list	*stack_b;

	len = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	numbers = parse(argc, argv, &len);
	if (!numbers)
		return (ft_putstr_fd("Error\n", 2), 0);
	if (!find_duplicates(numbers, len, &stack_a))
		return (ft_lstclear(&stack_a, free), free(numbers),
			ft_putstr_fd("Error\n", 2), 0);
	if (len <= 1 || is_sorted(stack_a))
		return (free(numbers), ft_lstclear(&stack_a, free), 0);
	if (len <= 5)
		simple_sort(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);
	free(numbers);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
