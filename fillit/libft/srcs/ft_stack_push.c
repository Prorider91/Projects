/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:50:14 by ffahey            #+#    #+#             */
/*   Updated: 2018/11/28 12:51:49 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_push(t_stack *stack, void *value)
{
	if (stack->top >= stack->s_size)
		ft_stack_resize(stack, stack->s_size);
	memcpy(&(stack->data[stack->top * stack->d_size]), value, stack->d_size);
	stack->top++;
}
