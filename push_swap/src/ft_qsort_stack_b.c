/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort_stack_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:42:52 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/27 13:59:29 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_for_little_size(t_stack *a, t_stack *b,
		int size, t_list **head)
{
	if (size == 1)
	{
		ft_lst_add(head, ft_pa(a, b));
	}
	else if (size == 2)
	{
		if (b->data[b->top] < b->data[b->top - 1])
			ft_lst_add(head, ft_sb(a, b));
		ft_lst_add(head, ft_pa(a, b));
		ft_lst_add(head, ft_pa(a, b));
	}
	return (1);
}

void			ft_qsort_stack_b(t_stack *a, t_stack *b,
		int size, t_list **head)
{
	int		push_count;
	int		rot_count;
	float	pivot;
	int		i;

	if (size < 3 && ft_for_little_size(a, b, size, head))
		return ;
	pivot = ft_get_median(&(b->data[b->top - size + 1]), size);
	push_count = 0;
	rot_count = 0;
	while (push_count + rot_count < size)
	{
		(float)b->data[b->top] > pivot ? push_count++ : rot_count++;
		if ((float)b->data[b->top] > pivot)
			ft_lst_add(head, ft_pa(a, b));
		else
			ft_lst_add(head, ft_rb(a, b));
	}
	ft_qsort_stack_a(a, b, push_count, head);
	i = 0;
	while (i++ < rot_count)
		ft_lst_add(head, ft_rrb(a, b));
	ft_qsort_stack_b(a, b, rot_count, head);
}
