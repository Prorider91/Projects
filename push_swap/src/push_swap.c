/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:20:07 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/27 19:16:40 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	t_list	*command_line;

	command_line = NULL;
	if (ft_init_stacks(&a, &b, argc, argv) == 0)
		return (0);
	if (a->size < 6)
		ft_little_sort(a, b, a->size, &command_line);
	else
		ft_qsort_stack_a(a, b, a->size, &command_line);
	if (command_line)
	{
		ft_lst_rev(&command_line);
		ft_command_optimization1(&command_line);
		ft_lst_print(command_line);
		ft_lst_free(&command_line);
	}
	ft_stk_delete(a);
	ft_stk_delete(b);
	return (0);
}
