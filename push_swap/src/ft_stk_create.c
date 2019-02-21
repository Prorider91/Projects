/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:15:55 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/27 19:08:10 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*ft_stk_create(size_t size, char flags)
{
	t_stack		*s;
	size_t		i;

	i = 0;
	s = NULL;
	if (size)
	{
		if (!(s = (t_stack*)malloc(sizeof(t_stack))))
			exit(OUT_OF_MEMORY);
		if (!(s->data = (int*)malloc(size * sizeof(int))))
			exit(OUT_OF_MEMORY);
		while (i < size)
			s->data[i++] = 0;
		s->size = size;
		s->top = -1;
		s->flags = flags;
		s->index1 = -1;
		s->index2 = -1;
	}
	return (s);
}

void	ft_stk_delete(t_stack *stack)
{
	if (stack)
	{
		free(stack->data);
		free(stack);
	}
}
