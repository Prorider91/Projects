/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:47:08 by ffahey            #+#    #+#             */
/*   Updated: 2018/11/28 12:48:22 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_stack_delete(t_stack **stack)
{
	if (stack && *stack)
	{
		free((*stack)->data);
		free(*stack);
		*stack = NULL;
	}
}
