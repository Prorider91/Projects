/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:42:30 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/27 17:58:47 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float			ft_get_median(int *arr, size_t size)
{
	int		*sort;
	float	pivot;

	sort = ft_int_bubble_sort(arr, size);
	pivot = sort[size / 2];
	free(sort);
	return (pivot);
}

int				ft_check_sort(int *arr, int size)
{
	int		i;

	i = 1;
	while (i < size)
	{
		if (arr[i] > arr[i - 1])
			return (0);
		i++;
	}
	return (1);
}

static void		ft_rotate_back(t_stack *a, t_stack *b,
		int rot_count, t_list **head)
{
	int		i;

	i = 0;
	while (i < rot_count)
	{
		ft_lst_add(head, ft_rra(a, b));
		i++;
	}
}

void			ft_qsort_stack_a(t_stack *a, t_stack *b,
		int size, t_list **head)
{
	int		push_count;
	int		rot_count;
	float	pivot;

	if (size <= 2 || ft_check_sort(&(a->data[a->top - size + 1]), size))
	{
		if (a->data[a->top] > a->data[a->top - 1])
			ft_lst_add(head, ft_sa(a, b));
		return ;
	}
	rot_count = 0;
	push_count = 0;
	pivot = ft_get_median(&(a->data[a->top - size + 1]), size);
	while (push_count + rot_count < size)
	{
		(float)(a->data[a->top]) < pivot ? push_count++ : rot_count++;
		if ((float)(a->data[a->top]) < pivot)
			ft_lst_add(head, ft_pb(a, b));
		else
			ft_lst_add(head, ft_ra(a, b));
	}
	if (a->top + 1 > size - push_count)
		ft_rotate_back(a, b, rot_count, head);
	ft_qsort_stack_a(a, b, rot_count, head);
	ft_qsort_stack_b(a, b, push_count, head);
}
