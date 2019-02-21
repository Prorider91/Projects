/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:05:05 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/26 15:43:10 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_ra(t_stack *a, t_stack *b)
{
	int		tmp;

	b->index1 = -1;
	b->index2 = -1;
	if (a && a->top > 0)
	{
		tmp = a->data[a->top];
		ft_memmove(a->data + 1, a->data, a->top * sizeof(int));
		a->data[0] = tmp;
	}
	a->index1 = 0;
	a->index2 = a->top + 1;
	return ("ra\n");
}

char	*ft_rb(t_stack *a, t_stack *b)
{
	int		tmp;

	a->index1 = -1;
	a->index2 = -1;
	if (b && b->top > 0)
	{
		tmp = b->data[b->top];
		ft_memmove(b->data + 1, b->data, b->top * sizeof(int));
		b->data[0] = tmp;
	}
	b->index1 = 0;
	b->index2 = b->top + 1;
	return ("rb\n");
}

char	*ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a, b);
	ft_rb(a, b);
	a->index1 = 0;
	a->index2 = a->top + 1;
	return ("rr\n");
}
