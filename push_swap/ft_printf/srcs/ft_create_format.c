/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:40:54 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/10 18:12:44 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_create_format(void)
{
	t_format	*format;

	format = (t_format*)malloc(sizeof(t_format));
	if (format)
	{
		format->spec = 0;
		format->flags = 0;
		format->precision = 0;
		format->width = 0;
	}
	return (format);
}
