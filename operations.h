/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 11:33:01 by asadik            #+#    #+#             */
/*   Updated: 2026/03/22 11:34:42 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "libft/libft.h"

void	swap(t_list *stack, char *str);
void	push(t_list **origin, t_list **target, char *str);
void	rotate(t_list **stack, char *str);
void	reverse_rotate(t_list **stack, char *str);

#endif