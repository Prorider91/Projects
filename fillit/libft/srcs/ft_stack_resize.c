/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_resize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:48:41 by ffahey            #+#    #+#             */
/*   Updated: 2018/11/28 13:00:10 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_stack_resize(t_stack *stack, unsigned int multiplier)
{
	void	*tmp;

	if (stack)
	{
		if (!(tmp = malloc(stack->s_size * stack->d_size * multiplier)))
			return ;
		stack->s_size *= multiplier;
		ft_memcpy(tmp, stack->data, stack->top * stack->d_size);
		free(stack->data);
		stack->data = tmp;
	}
}
