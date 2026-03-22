/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 11:39:26 by asadik            #+#    #+#             */
/*   Updated: 2026/03/22 11:40:13 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "libft/libft.h"

int		*parse(int argc, char **argv, int *len);
bool	find_duplicates(int *numbers, int len, t_list **stack_a);

#endif