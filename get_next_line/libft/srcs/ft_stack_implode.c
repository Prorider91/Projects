/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_implode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:56:15 by ffahey            #+#    #+#             */
/*   Updated: 2018/11/28 12:59:53 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_stack_implode(t_stack *stack)
{
	void	*tmp;

	if (stack)
	{
		if (!(tmp = malloc(stack->top * stack->d_size)))
			return ;
		stack->s_size = stack->top;
		ft_memcpy(tmp, stack->data, stack->top * stack->d_size);
		free(stack->data);
		stack->data = tmp;
	}
}
