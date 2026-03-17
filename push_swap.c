/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:12:32 by asadik            #+#    #+#             */
/*   Updated: 2026/03/17 17:21:34 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "libft/error_handling.h"
#include "libft/ft_printf/ft_printf.h"
#include "libft/libft.h"

int	*parse_args(char **args, int *len)
{
	int			*numbers;
	t_result	current;
	int			i;

	i = 0;
	while (args[*len])
		*len = *len + 1;
	if (len == 0)
		exit(EXIT_SUCCESS);
	numbers = ft_calloc(*len, sizeof(int));
	while (i < *len && numbers)
	{
		current = ft_atoi(args[i]);
		if (current.type == ERROR)
		{
			free(numbers);
			numbers = NULL;
			break;
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
		split = false;
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
		return(NULL);
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

static bool	find_duplicates(int *numbers, int len)
{
	int	i;
	int	e;

	i = 0;
	e = 1;
	while (i < len)
	{
		while (e < len)
		{
			if (numbers[i] == numbers[e])
				return false;
			e++;
		}
		i++;
		e = i + 1;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*numbers;
	int	len;

	len = 0;
	if (argc < 2)
		return (0);
	numbers = parse(argc, argv, &len);
	if (!numbers)
		return (ft_printf("Error\n"), 0);
	if (!find_duplicates(numbers, len))
		return (ft_printf("Error\n"), 0);
	for (i = 0; i < len; i++)
			ft_printf("%d\n", numbers[i]);
	free(numbers);
}
