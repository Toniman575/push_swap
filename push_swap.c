/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:12:32 by asadik            #+#    #+#             */
/*   Updated: 2026/03/20 20:40:59 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "libft/error_handling.h"
#include "libft/ft_printf/ft_printf.h"
#include "libft/ft_printf/ft_printf_util.h"
#include "libft/libft.h"

int	*parse_args(char **args, int *len)
{
	int			*numbers;
	t_result	current;
	int			i;

	i = 0;
	while (args[*len])
		*len = *len + 1;
	numbers = ft_calloc(*len, sizeof(int));
	while (i < *len && numbers)
	{
		current = ft_atoi(args[i]);
		if (current.type == ERROR)
		{
			free(numbers);
			numbers = NULL;
			break ;
		}
		else
			numbers[i] = current.value.n;
		i++;
	}
	return (numbers);
}

char	**read_args(int argc, char **argv, bool *split)
{
	char	**args;
	int		i;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		*split = true;
	}
	else
	{
		*split = false;
		i = 1;
		args = ft_calloc(argc, sizeof(char *));
		if (!args)
			return (args);
		while (i < argc)
		{
			args[i - 1] = argv[i];
			i++;
		}
		args[i - 1] = NULL;
	}
	return (args);
}

int	*parse(int argc, char **argv, int *len)
{
	char	**args;
	int		*numbers;
	bool	split;
	int		i;

	split = false;
	args = read_args(argc, argv, &split);
	if (!args)
		return (NULL);
	numbers = parse_args(args, len);
	if (split)
	{
		i = 0;
		while (args[i])
		{
			free(args[i]);
			i++;
		}
	}
	free(args);
	if (!numbers)
		return (NULL);
	return (numbers);
}

bool	create_stack(int *current, int index, t_list **stack_a)
{
	t_list	*new_node;

	current = ft_calloc(1, sizeof(int));
	if (!current)
		return (false);
	*current = index;
	new_node = ft_lstnew(current);
	if (!new_node)
	{
		free(current);
		return (false);
	}
	ft_lstadd_back(stack_a, new_node);
	return (true);
}

static bool	find_duplicates(int *numbers, int len, t_list **stack_a)
{
	int	i;
	int	j;
	int	index;
	int	*current;

	current = NULL;
	i = 0;
	while (i < len)
	{
		index = 0;
		j = 0;
		while (j < len)
		{
			if (i != j && numbers[i] == numbers[j])
				return (false);
			if (numbers[j] < numbers[i])
				index++;
			j++;
		}
		if (!create_stack(current, index, stack_a))
			return (false);
		i++;
	}
	return (true);
}

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

static int	get_min_pos(t_list *stack, int val)
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

static void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	pos;
	int	current_min;

	size = ft_lstsize(*stack_a);
	current_min = 0;
	if (size == 2 && *(int *)(*stack_a)->content > \
		*(int *)(*stack_a)->next->content)
		swap(*stack_a, "sa");
	else
	{
		while (size > 3)
		{
			pos = get_min_pos(*stack_a, current_min);
			if (pos <= size / 2)
				while (pos-- > 0)
					rotate(stack_a, "ra");
			else
				while (pos++ < size)
					reverse_rotate(stack_a, "rra");
			push(stack_a, stack_b, "pb");
			size--;
			current_min++;
		}
		sort_3(stack_a);
		while (*stack_b)
			push(stack_b, stack_a, "pa");
	}
}

void radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		max_bits;
	int		i;
	int		j;

	size = ft_lstsize(*stack_a);
	max_bits = 0;
	while ((size - 1) >> max_bits != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (*stack_a)
			{
				if (((*(int *)(*stack_a)->content >> i) & 1) == 1)
					rotate(stack_a, "ra"); 
				else
					push(stack_a, stack_b, "pb");
				j++;
			}
			else
				break ;
		}
		while (*stack_b)
			push(stack_b, stack_a, "pa");
		i++;
	}
}

bool	is_sorted(t_list *stack_a)
{
	while (stack_a->next)
	{
		if (*(int *)stack_a->content > *(int *)stack_a->next->content)
			return (false);
		stack_a = stack_a->next;
	}
	return (1);
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
		return (ft_printf("Error\n"), 0);
	if (!find_duplicates(numbers, len, &stack_a))
		return (ft_lstclear(&stack_a, free), free(numbers),
			ft_printf("Error\n"), 0);
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
