/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 11:36:34 by asadik            #+#    #+#             */
/*   Updated: 2026/03/22 13:26:56 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/error_handling.h"
#include "libft/libft.h"
#include <stdbool.h>
#include <stdlib.h>

static int	*parse_args(char **args, int *len)
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

static char	**read_args(int argc, char **argv, bool *split)
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

static bool	create_stack(int index, t_list **stack_a)
{
	t_list	*new_node;
	int		*current;

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

bool	find_duplicates(int *numbers, int len, t_list **stack_a)
{
	int	i;
	int	j;
	int	index;

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
		if (!create_stack(index, stack_a))
			return (false);
		i++;
	}
	return (true);
}
