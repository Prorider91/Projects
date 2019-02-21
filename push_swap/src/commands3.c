/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:05:23 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/27 19:36:55 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_rra(t_stack *a, t_stack *b)
{
	int		tmp;

	b->index1 = -1;
	b->index2 = -1;
	if (a && a->top > 0)
	{
		tmp = a->data[0];
		ft_memmove(a->data, a->data + 1, a->top * sizeof(int));
		a->data[a->top] = tmp;
		a->index2 = 0;
		a->index1 = a->top;
	}
	return ("rra\n");
}

char	*ft_rrb(t_stack *a, t_stack *b)
{
	int		tmp;

	a->index1 = -1;
	a->index2 = -1;
	if (b && b->top > 0)
	{
		tmp = b->data[0];
		ft_memmove(b->data, b->data + 1, b->top * sizeof(int));
		b->data[b->top] = tmp;
		b->index2 = 0;
		b->index1 = a->top;
	}
	return ("rrb\n");
}

char	*ft_rrr(t_stack *a, t_stack *b)
{
	ft_rra(a, b);
	ft_rrb(a, b);
	a->index2 = 0;
	a->index1 = a->top;
	return ("rrr\n");
}
