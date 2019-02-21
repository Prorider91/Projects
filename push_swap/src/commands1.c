/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:04:48 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/26 15:39:49 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_sa(t_stack *a, t_stack *b)
{
	b->index1 = -1;
	b->index2 = -1;
	if (a && a->top > 0)
		ft_int_swap(&(a->data[a->top]), &a->data[a->top - 1]);
	a->index1 = a->top;
	a->index2 = a->top - 1;
	return ("sa\n");
}

char	*ft_sb(t_stack *a, t_stack *b)
{
	a->index1 = -1;
	a->index2 = -1;
	if (b && b->top > 0)
		ft_int_swap(&(b->data[b->top]), &b->data[b->top - 1]);
	b->index1 = b->top;
	b->index2 = b->top - 1;
	return ("sb\n");
}

char	*ft_ss(t_stack *a, t_stack *b)
{
	ft_sa(a, b);
	ft_sb(a, b);
	a->index1 = a->top;
	a->index2 = a->top - 1;
	return ("ss\n");
}

char	*ft_pa(t_stack *dst, t_stack *src)
{
	if (dst && src && src->top >= 0)
	{
		dst->top++;
		dst->index1 = dst->top;
		dst->index2 = -1;
		ft_int_swap(&(dst->data[dst->top]), &(src->data[src->top]));
		src->index1 = -1;
		src->index2 = src->top;
		src->top--;
	}
	return ("pa\n");
}

char	*ft_pb(t_stack *src, t_stack *dst)
{
	if (dst && src && src->top >= 0)
	{
		dst->top++;
		dst->index1 = dst->top;
		dst->index2 = -1;
		ft_int_swap(&(dst->data[dst->top]), &(src->data[src->top]));
		src->index1 = -1;
		src->index2 = src->top;
		src->top--;
	}
	return ("pb\n");
}
