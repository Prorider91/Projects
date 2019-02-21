/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:52:02 by ffahey            #+#    #+#             */
/*   Updated: 2018/11/28 12:54:37 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_stack_pop(t_stack *stack)
{
	if (!stack || stack->top == 0)
		return (NULL);
	stack->top--;
	return (&(stack->data[stack->top * stack->d_size]));
}
