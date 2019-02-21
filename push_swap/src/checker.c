/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:19:26 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/27 19:15:16 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_check_sorting(t_stack *a, t_stack *b)
{
	size_t	i;

	if (a && b && b->top == -1)
	{
		i = 1;
		while (i < a->size)
		{
			if (a->data[i] > a->data[i - 1])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*command;

	a = NULL;
	b = NULL;
	command = NULL;
	if (ft_init_stacks(&a, &b, argc, argv) == 0)
		return (0);
	while (get_next_line(0, &command))
	{
		ft_apply_command(a, b, command);
		if (a->flags & DEBUG_FLAG)
		{
			ft_putstr(command);
			ft_print_stack(a, b);
			ft_putchar('\n');
		}
		free(command);
	}
	ft_putstr(ft_check_sorting(a, b) ? "OK\n" : "KO\n");
	ft_stk_delete(a);
	ft_stk_delete(b);
	return (0);
}
