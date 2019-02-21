/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 20:41:26 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/27 19:03:55 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_less_then_4_sort(t_stack *a, t_stack *b, t_list **head)
{
	while (1)
	{
		if (a->data[a->top] > a->data[a->top - 1])
			ft_lst_add(head, ft_sa(a, b));
		if (ft_check_sort(a->data, a->top + 1))
			break ;
		ft_lst_add(head, ft_rra(a, b));
	}
}

void		ft_little_sort(t_stack *a, t_stack *b, int size, t_list **head)
{
	float	median;

	median = 0.0;
	if (size > 3)
	{
		median = ft_get_median(a->data, size);
		while (size > 0)
		{
			if (a->data[a->top] < median)
				ft_lst_add(head, ft_pb(a, b));
			else
				ft_lst_add(head, ft_ra(a, b));
			size--;
		}
		ft_less_then_4_sort(a, b, head);
		if (b->top && b->data[b->top] < b->data[b->top - 1])
			ft_lst_add(head, ft_sb(a, b));
		while (b->top >= 0)
		{
			ft_lst_add(head, ft_pa(a, b));
		}
	}
	else
		ft_less_then_4_sort(a, b, head);
}
