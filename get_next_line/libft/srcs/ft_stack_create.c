/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:45:12 by ffahey            #+#    #+#             */
/*   Updated: 2018/11/28 12:59:32 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_stack		*ft_stack_create(size_t stack_size, size_t data_size)
{
	t_stack		*out;

	out = NULL;
	if (!(out = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	out->s_size = stack_size;
	out->d_size = data_size;
	if (!(out->data = malloc(out->s_size * out->d_size)))
	{
		free(out);
		return (NULL);
	}
	out->top = 0;
	return (out);
}
