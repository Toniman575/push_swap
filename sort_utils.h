/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 12:31:11 by asadik            #+#    #+#             */
/*   Updated: 2026/03/22 13:22:23 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_UTILS_H
# define SORT_UTILS_H
# include "libft/libft.h"

int		get_min_pos(t_list *stack, int val);
void	init_radix(int *size, t_list **stack_a, int *max_bits, int *i);
void	rotate_or_push(t_list **stack_a, t_list **stack_b, int i);

#endif