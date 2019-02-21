/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_peek.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:54:50 by ffahey            #+#    #+#             */
/*   Updated: 2018/11/28 12:55:56 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_stack_peek(const t_stack *stack)
{
	if (!stack || stack->top == 0)
		return (NULL);
	return (&(stack->data[(stack->top - 1) * stack->d_size]));
}
