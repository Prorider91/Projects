/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:29:56 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/26 18:07:39 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/includes/ft_printf.h"

static char	*ft_color_select(t_stack *a, int i)
{
	if (i == a->index1)
		return (GREEN);
	else if (i == a->index2)
		return (RED);
	else
		return (NORMAL);
}

void		ft_print_stack(t_stack *a, t_stack *b)
{
	int		i;
	char	*color;

	color = NORMAL;
	i = a->top > b->top ? a->top + 1 : b->top + 1;
	ft_putstr("\n---------------\n");
	while (i >= 0)
	{
		if (a->flags & COLOR_FLAG)
			color = ft_color_select(a, i);
		if (a->top >= i)
			ft_printf("%s%-10d%s", color, a->data[i], NORMAL);
		else
			ft_printf("%s%-10c%s", color, '.', NORMAL);
		if (a->flags & COLOR_FLAG)
			color = ft_color_select(b, i);
		if (b->top >= i)
			ft_printf("%s%-10d\n%s", color, b->data[i], NORMAL);
		else
			ft_printf("%s%-10c\n%s", color, '.', NORMAL);
		i--;
	}
	ft_putstr(NORMAL);
	ft_putstr("-----     -----     \n");
	ft_putstr("| a |     | b |     \n");
}
